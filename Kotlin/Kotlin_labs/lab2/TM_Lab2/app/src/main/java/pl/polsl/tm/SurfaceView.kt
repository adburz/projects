package pl.polsl.tm

import MyGLRenderer
import android.content.Context
import android.opengl.GLSurfaceView

class MyGLSurfaceView(context: Context) : GLSurfaceView(context) {

    private val renderer: MyGLRenderer

    init {

        // Create an OpenGL ES 2.0 context
        setEGLContextClientVersion(2)
        renderer = MyGLRenderer()
        // Set the Renderer for drawing on the GLSurfaceView
        setRenderer(renderer)
    }

    public fun SetDirection(dir: Int)
    {
        renderer.direction = dir;
    }

    public fun SetSpeed(speed: Float)
    {
        renderer.speed = speed;
    }
}
