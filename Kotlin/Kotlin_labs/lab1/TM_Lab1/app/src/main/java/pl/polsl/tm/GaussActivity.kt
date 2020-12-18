package pl.polsl.tm

import android.app.Activity
import android.graphics.Color.rgb
import android.os.Bundle
import android.view.View
import android.widget.Button
import androidx.appcompat.app.AppCompatActivity
import com.jjoe64.graphview.GraphView
import com.jjoe64.graphview.series.DataPoint
import com.jjoe64.graphview.series.LineGraphSeries
import com.jjoe64.graphview.series.PointsGraphSeries
import java.lang.Math.abs


class GaussActivity : Activity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_gauss)

        val _backButton: Button = this.findViewById<Button>(R.id.back_button)
        _backButton.setOnClickListener { back_button_click(_backButton)}


        val rel = intent.getDoubleExtra("realis", 0.0)
        val im = intent.getDoubleExtra("imaginalis", 0.0)


        val series = PointsGraphSeries(arrayOf(DataPoint(rel, im)))

        val graph = findViewById(R.id.gauss_graph) as GraphView

        graph.addSeries(series)

        graph.getGridLabelRenderer().setHorizontalLabelsVisible(true)
        graph.gridLabelRenderer.setVerticalLabelsVisible(true)

        graph.getGridLabelRenderer().setVerticalAxisTitle("Re")
        graph.getGridLabelRenderer().setHorizontalAxisTitle("Im")

        graph.getViewport().setXAxisBoundsManual(true)
        graph.getViewport().setYAxisBoundsManual(true)

        val valueRe = abs(rel) * 1.8
        val valueIm = abs(im) * 1.8

        graph.getViewport().setMaxX(valueRe)
        graph.getViewport().setMinX(-valueRe)
        graph.getViewport().setMaxY(valueIm)
        graph.getViewport().setMinY(-valueIm)

    }
    fun back_button_click(v: View?)
    {
        finish()
    }
}