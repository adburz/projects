package pl.polsl.tm

import android.hardware.Sensor
import android.hardware.SensorEventListener
import android.hardware.SensorManager
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.content.Context
import android.hardware.SensorEvent
import android.media.MediaPlayer
import android.util.Log
import kotlin.math.abs

class MainActivity : AppCompatActivity(), SensorEventListener {

    private lateinit var gLView: MyGLSurfaceView
    private lateinit var sensor: SensorManager
    private var accelerometer: Sensor? = null

    companion object {
        private lateinit var sound : MediaPlayer
        fun PlaySound() {
            sound.start();
        }
    }
    public override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        // Create a GLSurfaceView instance and set it
        // as the ContentView for this Activity.
        gLView = MyGLSurfaceView(this)
        setContentView(gLView)

        sensor = getSystemService(Context.SENSOR_SERVICE) as SensorManager
        sensor.getDefaultSensor(Sensor.TYPE_ACCELEROMETER)?.let {
            accelerometer = it
        }

        sound = MediaPlayer.create(this, R.raw.pilka);

        sensor.registerListener(this, accelerometer, SensorManager.SENSOR_DELAY_NORMAL)
    }

    override fun onSensorChanged(event: SensorEvent?) {
        if (event?.sensor?.type == Sensor.TYPE_ACCELEROMETER) {
            // convert the rotation-vector to a 4x4 matrix. the matrix
            // is interpreted by Open GL as the inverse of the
            // rotation-vector, which is what we want.
            if(event.values[1].toFloat() > 0f)
                gLView.SetDirection(1);
            else
                gLView.SetDirection(-1);
            gLView.SetSpeed(abs(event.values[1].toFloat()/165))
            Log.v("Y", event.values[1].toString());
        }
    }

    override fun onAccuracyChanged(p0: Sensor?, p1: Int) {
    }
}