package pl.polsl.lab.controller;
import javafx.scene.Scene;
import pl.polsl.lab.ScenesController;
import pl.polsl.lab.utils.Doctor;
import pl.polsl.lab.model.Patient;
import pl.polsl.lab.exceptions.PatientParamsException;
import pl.polsl.lab.model.PatientsList;
import pl.polsl.lab.view.PatientView;

import java.util.Scanner;

/**
 * Represents controller of MVC structure, which operates on model and view structures.
 * @version 1.0
 */
public class PatientController {

    /**
     * One of the doctors
     */
    private Doctor d;
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
     */
    public PatientController() {
        scan = new Scanner(System.in);
        this.model = new PatientsList();
        this.view = new PatientView();
    }

    /**
     * Method used to run javaFX application.
     */
    public void run(){
        ScenesController.setScenes(ProgramTypeController.class);
        ScenesController.getController(ProgramTypeController.class).setView(view);
        ScenesController.getController(ProgramTypeController.class).setModel(model);
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
                case "3":
                    checkPatientsCount();
                    break;
            }
        }
        while(!input.equals("9"));
        view.printClosing();
        model.saveModelData(dbPath);
        return;
    }

    /**
     * Method returns number of patients corresponding to doctor
     */
    private void checkPatientsCount()
    {
        Doctor doctor = chooseDoctor();
        if(doctor == null)
            return;
        int count = model.getPatientsCount(doctor);
        view.printPatientsCount(doctor, count);
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
     * @param doctor doctor to whom the patient is registered.
     * @return boolean information about success of adding operation.
     */
    private boolean addRegistration(String name, String lastName, String pesel, String phoneNum, Doctor doctor)
    {
        Integer new_id;
        try {
             new_id = model.addPatient(name, lastName, pesel, phoneNum, doctor);
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
     * Method used to define the doctor to whom patient will be registered.
     * @return enum type of the chosen doctor
     */
    private Doctor chooseDoctor()
    {
        view.printDoctorSelectionView();
        String chosenDoctor = scan.nextLine();
        if(chosenDoctor.equals("1"))
        {return Doctor.Smith;}
        else if(chosenDoctor.equals("2"))
        {return Doctor.Johnson;}
        else if(chosenDoctor.equals("3"))
        {return Doctor.Williams;}
        else
        { return null;}
    }
    /**
     * Method gets information from user (name/last name/PESEL/phone number/doctor) and finally loads it to another function to add new user.
     */
    private void newRegistration()
    {
        Doctor doctor = chooseDoctor();
        if(doctor==null)
        {
            return;
        }

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
            if(addRegistration(name, lastName, pesel, phoneNum, doctor))
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
            view.printRegInfo(info.getFirstName(), info.getLastName(), info.getPesel(), info.getPhoneNum(), info.getDate(), info.getDoctor());
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
