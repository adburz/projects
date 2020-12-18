package pl.polsl.tm

import android.content.res.Resources
import android.opengl.GLES20
import android.opengl.Matrix
import android.util.Log
import java.nio.ByteBuffer
import java.nio.ByteOrder
import java.nio.FloatBuffer


class Circle internal constructor() {
    private val mProgram: Int
    private var mPositionHandle = 0
    private var mColorHandle = 0
    private var mMVPMatrixHandle = 0
    private val mVertexBuffer: FloatBuffer
    private val vertices = FloatArray(364 * 3)
    var color = floatArrayOf(0f, 0f, 1f, 1.0f)

    private val vertexShaderCode = "uniform mat4 uMVPMatrix;" +
            "attribute vec4 vPosition;" +
            "void main() {" +
            "  gl_Position = uMVPMatrix * vPosition;" +
            "}"
    private val fragmentShaderCode = "precision mediump float;" +
            "uniform vec4 vColor;" +
            "void main() {" +
            "  gl_FragColor = vColor;" +
            "}"

    public val mModelMatrix = FloatArray(16)

    fun draw(mvpMatrix: FloatArray?) {
        GLES20.glUseProgram(mProgram)

        // get handle to vertex shader's vPosition member
        mPositionHandle = GLES20.glGetAttribLocation(mProgram, "vPosition")

        // Enable a handle to the circle vertices
        GLES20.glEnableVertexAttribArray(mPositionHandle)

        // Prepare the circle coordinate data
        GLES20.glVertexAttribPointer(
                mPositionHandle, 3,
                GLES20.GL_FLOAT, false, 12, mVertexBuffer
        )
        // get handle to fragment shader's vColor member
        mColorHandle = GLES20.glGetUniformLocation(mProgram, "vColor")

        // Set color for drawing the circle
        GLES20.glUniform4fv(mColorHandle, 1, color, 0)
        mMVPMatrixHandle = GLES20.glGetUniformLocation(mProgram, "uMVPMatrix")

        // Apply the projection and view transformation
        GLES20.glUniformMatrix4fv(mMVPMatrixHandle, 1, false, mvpMatrix, 0)

        // Draw the circle
        GLES20.glDrawArrays(GLES20.GL_TRIANGLE_FAN, 0, 364)

        // Disable vertex array
        GLES20.glDisableVertexAttribArray(mPositionHandle)
    }

    companion object {
        fun loadShader(type: Int, shaderCode: String?): Int {
            val shader = GLES20.glCreateShader(type)
            GLES20.glShaderSource(shader, shaderCode)
            GLES20.glCompileShader(shader)
            return shader
        }
    }

    init {
        Matrix.setIdentityM(mModelMatrix, 0)
        vertices[0] = 0F
        vertices[1] = 0F
        vertices[2] = 0F
        val ratio = Resources.getSystem().displayMetrics.widthPixels.toFloat() / Resources.getSystem().displayMetrics.heightPixels.toFloat()
        for (i in 1..363) { // 1.0 is is a full size of screen
            vertices[i * 3 + 0] = (ratio * 0.1 * Math.cos(3.14 / 180 * i.toFloat())).toFloat()
            vertices[i * 3 + 1] = (ratio * 0.1* Math.sin(3.14 / 180 * i.toFloat())).toFloat()
            vertices[i * 3 + 2] = 0F
        }
        Log.v("Thread", "" + vertices[0] + "," + vertices[1] + "," + vertices[2])
        val vertexByteBuffer = ByteBuffer.allocateDirect(vertices.size * 4)
        vertexByteBuffer.order(ByteOrder.nativeOrder())
        mVertexBuffer = vertexByteBuffer.asFloatBuffer()
        mVertexBuffer.put(vertices)
        mVertexBuffer.position(0)
        val vertexShader = loadShader(GLES20.GL_VERTEX_SHADER, vertexShaderCode)
        val fragmentShader = loadShader(GLES20.GL_FRAGMENT_SHADER, fragmentShaderCode)
        mProgram = GLES20.glCreateProgram() // create empty OpenGL ES Program
        GLES20.glAttachShader(mProgram, vertexShader) // add the vertex shader to program
        GLES20.glAttachShader(mProgram, fragmentShader) // add the fragment shader to program
        GLES20.glLinkProgram(mProgram)
    }
}

