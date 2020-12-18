package pl.polsl.lab.patients.controller;
import pl.polsl.lab.patients.model.Patient;
import pl.polsl.lab.patients.exceptions.PatientParamsException;
import pl.polsl.lab.patients.model.PatientsList;
import pl.polsl.lab.patients.view.PatientView;

import javax.swing.*;
import java.util.Scanner;


/**
 * Represents controller of MVC structure, which operates on model and view structures.
 * @version 1.0
 */
public class PatientController {

    /**
     * Path to data base file.
     */
    private String dbPath;

    /**
     *  Model class object.
     */
    private PatientsList model;

    /**
     *  View class object
     */
    private PatientView view;

    /**
     *  Object of Scanner object, used to get input from user in console.
     */
    private Scanner scan;

    /**
     * Instantiates a new Patient controller. It also create new model and view objects.
     * @param filePath the file path
     */
    public PatientController(String filePath) {
        dbPath = filePath;
        scan = new Scanner(System.in);
        this.model = new PatientsList(filePath);
        this.view = new PatientView();
    }


    /**
     * Initialization of controller. It contains main loop which keeps program up.
     */
    public void initController()
    {
        String input;
        do
        {
            initView();
            input = scan.nextLine();

            switch(input)
            {
                case "1":   //new register
                    newRegistration();
                    break;
                case "2":   //check register date
                    checkRegistration();
                    break;
            }
        }
        while(!input.equals("9"));
        view.printClosing();
        model.saveModelData(dbPath);
        return;
    }

    /**
     *  Printing main-first page of application.
     */
    private void initView()
    {
        view.printFirstPage();
    }

    /**
     * Method used to control model method .addPatient. It supports exceptions by try{} catch(){} blocks.
     * @param name name of user to be added.
     * @param lastName last name of user to be added.
     * @param pesel PESEL of user to be added.
     * @param phoneNum phone number of user to be added.
     * @return boolean information about success of adding operation.
     */
    private boolean addRegistration(String name, String lastName, String pesel, String phoneNum)
    {
        Integer new_id;
        try {
             new_id = model.addPatient(name, lastName, pesel, phoneNum);
        }
        catch(PatientParamsException e)
        {
            e.PrintErrorMessage();
            view.printRegistrationFailed();
            return false;
        }

        view.printRegEnd(new_id);
        return true;

    }

    /**
     * Method gets information from user (name/last name/PESEL/phone number) and finally loads it to another function to add new user.
     */
    private void newRegistration()
    {
        view.printNewRegistrationView();

        view.printGetNameView();
        String name = scan.nextLine();

        view.printGetLastNameView();
        String lastName = scan.nextLine();

        view.printGetPeselView();
        String pesel = scan.nextLine();

        view.printGetPhoneNumView();
        String phoneNum = scan.nextLine();

        view.printConfirmRegistration(name, lastName, pesel, phoneNum);
        String confirm = scan.nextLine();

        if(confirm.equals("1"))
        {
            if(addRegistration(name, lastName, pesel, phoneNum))
            {
                return;
            }
        }
        else
        {
            view.askIfNewRegistration();
            String ifAgain = scan.nextLine();
            if(ifAgain.equals("1"))
            {
                newRegistration();
            }
            else
            {
                return;
            }
        }
    }

    /**
     * Method to print information for user about registration by entered id from user.
     */
    private void checkRegistration()
    {
        view.printGetIdQuestion();
        int id = Integer.parseInt(scan.nextLine());
        Patient info = model.getInfoById(id);
        if(info != null)
        {
            view.printRegInfo(info.getFirstname(), info.getLastname(), info.getPesel(), info.getPhoneNum());
        }
        else
        {
            System.out.println("Registration with this ID does not exists.");
        }

        view.askIfGetBackToMenu();
        String ifAgain = scan.nextLine();
        if(ifAgain.equals("1"))
        {
            return;
        }
        else
        {
            checkRegistration();
        }
    }

}
