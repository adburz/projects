package pl.polsl.lab.Servlets;

import pl.polsl.lab.Model.Patient;
import pl.polsl.lab.Model.PatientsList;
import pl.polsl.lab.exceptions.PatientParamsException;
import pl.polsl.lab.utils.Doctor;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

@WebServlet(name = "patientsQueue", urlPatterns = {"/patientsQueue"})
public class PatientsQueueServlet extends HttpServlet {

    private  PatientsList model;

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
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();

        String docButtonName = request.getParameter("doctorName");

        int numberOfPatients = 0;
        List<Patient> tmPatients = null;
        if(docButtonName.equals("smith")){
            tmPatients = model.getChosenPatients(Doctor.Smith);
            numberOfPatients = model.getPatientsCount(Doctor.Smith);
        }else if(docButtonName.equals("johnson")){
            tmPatients = model.getChosenPatients(Doctor.Johnson);
            numberOfPatients = model.getPatientsCount(Doctor.Johnson);
        } else if(docButtonName.equals("williams")){
            tmPatients = model.getChosenPatients(Doctor.Williams);
            numberOfPatients = model.getPatientsCount(Doctor.Williams);
        }

        if(tmPatients!=null) {
            for (Patient p : tmPatients) {
                out.println("<tr>");

                out.println("<td>");
                out.println(p.getFirstName());
                out.println("</td>");
                out.println("<td>");
                out.println(p.getLastName());
                out.println("</td>");
                out.println("<td>");
                out.println(p.getPhoneNum());
                out.println("</td>");

                out.println("</tr>");
            }
        }

        out.println("<p>");
        out.println("Number of patients: ");
        out.println(Integer.toString(numberOfPatients));
        out.println("</p>");
        out.println("</br>");

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
