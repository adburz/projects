package pl.polsl.lab6przykladkotlin

import android.Manifest
import android.annotation.SuppressLint
import android.app.Activity
import android.content.pm.PackageManager
import android.location.Location
import android.location.LocationManager
import android.os.Build
import android.os.Bundle
import android.webkit.JavascriptInterface
import android.webkit.WebView
import android.widget.Toast
import androidx.annotation.RequiresApi

class Card : Activity() {

    private lateinit var gps : LocationManager
    private lateinit var page: WebView
    private var presents = ArrayList<String>()
    private var photoPath = ""
    private var latitude = 0.0
    private var longitude = 0.0
    private val REQUEST_LOCATION = 3
    private var isLocationAvailable = true

    @RequiresApi(Build.VERSION_CODES.M)
    @SuppressLint("JavascriptInterface")
    override fun onCreate(savedInstanceState: Bundle?){
        super.onCreate(savedInstanceState)
        presents = intent.getStringArrayListExtra("presentsList") as ArrayList<String>
        photoPath = intent.getStringExtra("photoPath").toString()

        page = WebView(this)
        page.settings.javaScriptEnabled=true

        page.addJavascriptInterface(this, "CardActivity")
        page.loadUrl("file:///android_asset/CardPage.html")
        setContentView(page)

        gps = getSystemService(LOCATION_SERVICE) as LocationManager
        loadLocalization()
    }


    @RequiresApi(Build.VERSION_CODES.M)
    override fun onRequestPermissionsResult(requestCode: Int, permissions: Array<out String>, grantResults: IntArray) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults)
        if(requestCode == REQUEST_LOCATION){
            if(grantResults[0] == PackageManager.PERMISSION_GRANTED && grantResults[1] == PackageManager.PERMISSION_GRANTED) {
                loadLocalization();
            } else {
                Toast.makeText(this, "No permission.", Toast.LENGTH_SHORT).show()
            }
        }
    }

    @RequiresApi(Build.VERSION_CODES.M)
    private fun loadLocalization(){
        val loc : Location

        if(checkSelfPermission(Manifest.permission.ACCESS_FINE_LOCATION) == PackageManager.PERMISSION_GRANTED
            && checkSelfPermission(Manifest.permission.ACCESS_COARSE_LOCATION) == PackageManager.PERMISSION_GRANTED) {
            if (gps.getLastKnownLocation(LocationManager.GPS_PROVIDER) != null){
                loc = gps.getLastKnownLocation(LocationManager.GPS_PROVIDER) as Location
                latitude = loc.latitude
                longitude = loc.longitude
            }
            else {
                Toast.makeText(this, "Can't read localization", Toast.LENGTH_LONG).show()
                isLocationAvailable = false
            }
        } else {
            requestPermissions(arrayOf(
                Manifest.permission.ACCESS_FINE_LOCATION,
                Manifest.permission.ACCESS_COARSE_LOCATION), REQUEST_LOCATION)
        }
    }

    @JavascriptInterface
    fun getPresentString() : String {
        return presents.joinToString(separator = ";")
    }

    @JavascriptInterface
    fun getPhotoPath() : String {
        return photoPath
    }

    @JavascriptInterface
    fun isLocationAviable() : Boolean {
        return isLocationAvailable
    }

    fun Double.format(digits: Int) = "%.${digits}f".format(this)
    @JavascriptInterface
    fun getLongitude(): String {
        return longitude.format(5)
    }

    @JavascriptInterface
    fun getLatitude(): String {
        return latitude.format(5)
    }
}

