package pl.polsl.lab6przykladkotlin

import android.annotation.SuppressLint
import android.content.ActivityNotFoundException
import android.content.Intent
import android.net.Uri
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.Environment
import android.provider.MediaStore
import android.speech.RecognizerIntent
import android.webkit.JavascriptInterface
import android.widget.Toast
import java.util.*
import android.webkit.WebView
import androidx.core.content.FileProvider
import java.io.File
import java.io.IOException
import java.text.SimpleDateFormat

class MainActivity : AppCompatActivity() {

    companion object {
        private const val REQUEST_CODE_STT = 1
        private const val REQUEST_IMAGE_CAPTURE = 2
    }

    private var presents = ArrayList<String>()
    private lateinit var page :WebView
    private var photoPath = ""


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        page = WebView(this)
        page.settings.javaScriptEnabled=true
        page.addJavascriptInterface(this, "PresentsActivity")
        page.loadUrl("file:///android_asset/StartPage.html")
        setContentView(page)
    }


    @JavascriptInterface //adnotacja sygnalizujaca ze metoda bedzie dostepna z poziomu JS
    fun addPresent() {
        var speech = Intent(RecognizerIntent.ACTION_RECOGNIZE_SPEECH)
        speech.putExtra(RecognizerIntent.EXTRA_PROMPT, "Say something!")
        speech.putExtra(RecognizerIntent.EXTRA_LANGUAGE_MODEL, RecognizerIntent.LANGUAGE_MODEL_FREE_FORM)
        try{
            startActivityForResult(speech, REQUEST_CODE_STT)
        } catch (ex: ActivityNotFoundException) {
            Toast.makeText(getApplicationContext(), "This device doesn't enable speech recognition!", Toast.LENGTH_SHORT).show();
        }
    }

    fun generateCard(){
        if(File(photoPath).length() != 0.toLong())
        {
            val cardActivity = Intent(this, Card::class.java).apply {
                putExtra("presentsList", presents)
                putExtra("photoPath", photoPath)
            }
            startActivity(cardActivity)
            presents.clear()
        } else {
            return
        }
    }

    override fun onActivityResult(requestCode: Int, resultCode: Int, data: Intent?) {
        super.onActivityResult(requestCode, resultCode, data)
        when(requestCode) {
            REQUEST_CODE_STT -> {
            if (data != null) {
                var wish = data.getStringArrayListExtra(RecognizerIntent.EXTRA_RESULTS)
                if (!wish.isNullOrEmpty()) {
                    val recognizedText = wish[0]
                    presents.add(recognizedText)
                    page.loadUrl("javascript:loadPresents()")
                    }
                }
            }
            REQUEST_IMAGE_CAPTURE -> {
                generateCard()
            }
        }
    }

    @JavascriptInterface
    fun getPresentString() : String{
        return presents.joinToString(separator = ";")
    }




    @Throws(IOException::class)
    private fun createImage(): File {
        val timeStamp: String = SimpleDateFormat("yyyyMMdd_HHmmss", Locale.US).format(Date())
        val storageDir: File = getExternalFilesDir(Environment.DIRECTORY_PICTURES)!!
        return File.createTempFile("STUDENT${timeStamp}_", ".jpg", storageDir).apply {
            photoPath = absolutePath
        }
    }


    @SuppressLint("QueryPermissionsNeeded")
    @JavascriptInterface
    fun dispatchTakePictureIntent() {
        Intent(MediaStore.ACTION_IMAGE_CAPTURE).also { takePictureIntent ->
            takePictureIntent.resolveActivity(packageManager)?.also {
                val photoFile: File? = try {
                    createImage()
                } catch (ex: IOException) {
                    Toast.makeText(this, "Error", Toast.LENGTH_LONG).show()
                    null
                }
                photoFile?.also {
                    val photoURI: Uri = FileProvider.getUriForFile(this, "pl.polsl.lab6przykladkotlin.fileprovider", it)
                    takePictureIntent.putExtra(MediaStore.EXTRA_OUTPUT, photoURI)
                    startActivityForResult(takePictureIntent, REQUEST_IMAGE_CAPTURE)
                }
            }
        }
    }
}