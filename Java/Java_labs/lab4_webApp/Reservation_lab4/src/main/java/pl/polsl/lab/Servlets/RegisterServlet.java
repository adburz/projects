package pl.polsl.lab.Servlets;

import pl.polsl.lab.Model.PatientsList;
import pl.polsl.lab.exceptions.PatientParamsException;
import pl.polsl.lab.utils.Doctor;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(name = "StartupServlet", urlPatterns = {"/register"})
public class RegisterServlet extends HttpServlet {

    private  PatientsList model;

    private Doctor loadDoctor(String doctor) {
        if (Integer.parseInt(doctor) == 1) {
            return Doctor.Smith;
        } else if (Integer.parseInt(doctor) == 2) {
            return Doctor.Johnson;
        } else if (Integer.parseInt(doctor) == 3) {
            return Doctor.Williams;
        } else {
        return null;
        }
    }

    private void provideModel(HttpServletRequest request){
        if((PatientsList) request.getSession().getServletContext().getAttribute("model") == null){
            this.model = new PatientsList();
            request.getSession().getServletContext().setAttribute("model", model);
        }
        else{
            this.model = (PatientsList) request.getSession().getServletContext().getAttribute("model");
        }
    }

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        provideModel(request);

        String firstName = request.getParameter("firstName");
        String lastName = request.getParameter("lastName");
        String pesel = request.getParameter("pesel");
        String phoneNumber = request.getParameter("phoneNumber");
        Doctor doctor = loadDoctor(request.getParameter("doctor"));

        try{
            model.addPatient(firstName, lastName, pesel, phoneNumber, doctor);
            response.setHeader("myMessage", "Successfully registered!");
        }catch(PatientParamsException e)
        {
            response.setHeader("myMessage", e.getMessage());
        }
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        provideModel(request);
        processRequest(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        provideModel(request);
        processRequest(request, response);
    }
}
