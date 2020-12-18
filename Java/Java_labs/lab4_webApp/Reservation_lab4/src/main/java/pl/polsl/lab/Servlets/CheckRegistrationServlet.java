package pl.polsl.lab.Servlets;

import pl.polsl.lab.Model.Patient;
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

@WebServlet(name = "checkRegistration", urlPatterns = {"/checkRegistration"})
public class CheckRegistrationServlet extends HttpServlet {

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

        int id = Integer.parseInt(request.getParameter("regId"));
        Patient info = model.getInfoById(id);
        if(info != null){
            out.println("<p>");
            out.println("Registration data:");
            out.println("<br>");
            out.println("Name:");
            out.println(info.getFirstName());
            out.println("<br>");
            out.println("Last name:");
            out.println(info.getLastName());
            out.println("<br>");
            out.println("PESEL:");
            out.println(info.getPesel());
            out.println("<br>");
            out.println("Phone number:");
            out.println(info.getPhoneNum());
            out.println("<br>");
            out.println("Date:");
            out.println(info.getDate());
            out.println("<br>");
            out.println("Doctor:");
            out.println(info.getDoctor().toString());
            out.println("</p>");
        } else{
            out.println("<p>");
            out.println("Can't find user with this ID.");
            out.println("<p>");
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
