import android.content.Context
import android.media.AudioAttributes
import android.media.MediaPlayer
import android.net.Uri
import javax.microedition.khronos.egl.EGLConfig
import javax.microedition.khronos.opengles.GL10

import android.opengl.GLES20
import android.opengl.GLSurfaceView
import android.opengl.Matrix
import pl.polsl.tm.Circle
import pl.polsl.tm.MainActivity

class MyGLRenderer : GLSurfaceView.Renderer {

    private lateinit var circle: Circle
    private val vPMatrix = FloatArray(16)
    private val projectionMatrix = FloatArray(16)
    private val viewMatrix = FloatArray(16)
    public var direction = 1
    public var speed = 0.005f
    private var ratio = 0f
    private val scratch = FloatArray(16)
    private var soundPlayed = false;

    override fun onDrawFrame(unused: GL10) {
        // Redraw background color
        GLES20.glClear(GLES20.GL_COLOR_BUFFER_BIT)

        // Set the camera position (View matrix)
        Matrix.setLookAtM(viewMatrix, 0, 0f, 0f, -3f, 0f, 0f, 0f, 0f, 1.0f, 0.0f)

        // Calculate the projection and view transformation
        Matrix.multiplyMM(vPMatrix, 0, projectionMatrix, 0, viewMatrix, 0)

        Matrix.translateM(circle.mModelMatrix, 0, speed * direction, 0f, 0f);

        //Checks if ball hits the screen's edge
        if(circle.mModelMatrix[12] >= ratio * 0.91) {
            Matrix.translateM(circle.mModelMatrix, 0, speed * direction * (-1), 0f, 0f);
            if(!soundPlayed)MainActivity.PlaySound();
            soundPlayed = true;
        } else if(circle.mModelMatrix[12] <= -ratio * 0.92){
            Matrix.translateM(circle.mModelMatrix, 0, speed * direction * (-1), 0f, 0f);
            if(!soundPlayed)MainActivity.PlaySound();
            soundPlayed = true;
        }
        else
        {
            soundPlayed = false;
        }

        //Calculate the scratch and translate matrix
        Matrix.multiplyMM(scratch, 0, vPMatrix, 0, circle.mModelMatrix, 0)

        //Draw element
        circle.draw(scratch)
    }

    override fun onSurfaceCreated(unused: GL10, config: EGLConfig) {
        // Set the background frame color
        GLES20.glClearColor(0f, 1.0f, 0f, 1.0f)
        circle = Circle()
    }

    override fun onSurfaceChanged(unused: GL10, width: Int, height: Int) {
        GLES20.glViewport(0, 0, width, height)

        ratio = width.toFloat() / height.toFloat()

        // this projection matrix is applied to object coordinates
        // in the onDrawFrame() method
        Matrix.frustumM(projectionMatrix, 0, -ratio, ratio, -1f, 1f, 3f, 7f)
    }
}