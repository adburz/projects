package pl.polsl.tm

import android.app.Activity
import android.content.Intent
import android.os.Bundle
import android.view.View
import android.widget.*
import java.math.BigDecimal

class MainActivity : Activity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val _plusButton: Button = this.findViewById<Button>(R.id.plusButton)
        _plusButton.setOnClickListener { mathButtonClick(_plusButton)}

        val _minusButton: Button = this.findViewById<Button>(R.id.minusButton)
        _minusButton.setOnClickListener{mathButtonClick(_minusButton)}


        // accesing string items from string resources
        val symbols = resources.getStringArray(R.array.symbols)
        // accesing the spinner
        val spinner = findViewById<Spinner>(R.id.spinner)

        if(spinner != null) {
            val adapter = ArrayAdapter(this,
                android.R.layout.simple_spinner_item, symbols)
            spinner.adapter = adapter

            spinner.onItemSelectedListener = object :
                AdapterView.OnItemSelectedListener{
                override fun onNothingSelected(parent: AdapterView<*>?) {
                    TODO("Not yet implemented")
                }

                override fun onItemSelected(parent: AdapterView<*>?,
                                            view: View?,
                                            position: Int,
                                            id: Long)
                {
                    if(symbols[position] == "+")
                    {
                        mathButtonClick(_plusButton)
                    }
                    else if(symbols[position] == "-")
                    {
                        mathButtonClick(_minusButton)
                    }
                }
            }
        }
    }

    fun printGauss(rel: BigDecimal, im: BigDecimal)
    {
        val intent = Intent(this, GaussActivity::class.java).apply {
            putExtra("realis", rel.toDouble());
            putExtra("imaginalis", im.toDouble())
        }
        startActivity(intent)

    }


    fun printToast(r: BigDecimal, i: BigDecimal)
    {
        Toast.makeText(this,
                (if(r>=BigDecimal(0)) r.toString() else '-' + r.toString()) +' '+
                        (if(i>=BigDecimal(0)) '+' + i.toString() else i.toString()) + "i", Toast.LENGTH_SHORT).show()
    }

    fun notEmpty() : Boolean
    {
        val re1 = findViewById<EditText>(R.id.Re1_editTextNumberUnsigned).text
        val re2 = findViewById<EditText>(R.id.Re1_editTextNumberUnsigned).text
        val im1 = findViewById<EditText>(R.id.Re1_editTextNumberUnsigned).text
        val im2 = findViewById<EditText>(R.id.Re1_editTextNumberUnsigned).text


        if(re1.isEmpty() && re2.isEmpty() && im1.isEmpty() && im2.isEmpty())  {
            return false
        }
            return true

    }

    /**Called when user taps the "+" button*/
    fun mathButtonClick(v: View?)
    {
        if(notEmpty()) {
            var re1 : BigDecimal = findViewById<EditText>(R.id.Re1_editTextNumberUnsigned).text.toString().toBigDecimalOrNull() ?: BigDecimal(0)
            var re2 : BigDecimal = findViewById<EditText>(R.id.Re2_editTextNumberUnsigned).text.toString().toBigDecimalOrNull() ?: BigDecimal(0)

            var im1 : BigDecimal = findViewById<EditText>(R.id.Im1_editTextNumberUnsigned).text.toString().toBigDecimalOrNull() ?: BigDecimal(0)
            var im2 : BigDecimal = findViewById<EditText>(R.id.Im2_editTextNumberUnsigned).text.toString().toBigDecimalOrNull() ?: BigDecimal(0)


            var result_rel : BigDecimal = BigDecimal(0)
            var result_im  : BigDecimal = BigDecimal(0)

            when (v?.id) {
                R.id.plusButton -> {
                    result_rel = re1 + re2
                    result_im = im1 + im2
                }

                R.id.minusButton -> {
                   result_rel = re1 - re2
                    result_im = im1 - im2
                }
            }


            printToast(result_rel, result_im)

            printGauss(result_rel, result_im)
        }
    }


}