package pl.polsl.lab.patients.view;


import pl.polsl.lab.patients.utils.Doctor;

import java.util.Date;

/**
 * Represents view structure of MVC, which prints and gets information from user using UI, in this case - console.
 * @version 1.0
 */
public class PatientView {

    /**
     * Print registration info.
     *
     * @param name     the name
     * @param lastName the last name
     * @param pesel    the PESEL
     * @param phoneNum the phone number
     * @param date date of registration
     * @param doctor chosen doctor by patient
     */
    public void printRegInfo(String name, String lastName, String pesel, String phoneNum, Date date, Doctor doctor)
    {
        System.out.println("\n   Registration data:");
        System.out.println("Name: "+ name);
        System.out.println("Last name: "+ lastName);
        System.out.println("PESEL: "+ pesel);
        System.out.println("Phone number: "+ phoneNum);
        System.out.println("Date: "+ date.toString());
        System.out.println("Doctor: "+ doctor.toString());
    }

    /**
     * Method prints information for user, that system has closed.
     */
    public void printClosing()
    {
        System.out.println("System closed.");
    }

    /**
     * Method prints information to user, that registration successfully. It prints also ID of new registration.
     * @param id the id
     */
    public void printRegEnd(Integer id)
    {
        System.out.println("Finally registered! Register id: " + id.toString());
    }

    /**
     * Method prints view which asks user if he/she wants to try to register again.
     */
    public void askIfNewRegistration()
    {
        System.out.println("Would you like to try register again?");
        System.out.println("1 -> Yes");
        System.out.println("(Other key) -> No");
    }

    /**
     * Ask if get back to menu.
     */
    public void askIfGetBackToMenu()
    {
        System.out.println("Would you like to get back into main menu?");
        System.out.println("1 -> Yes");
        System.out.println("(Other key) -> No");
    }

    /**
     * Method print question if confirm registration and passed data by user.
     *
     * @param name     the name
     * @param lastName the last name
     * @param pesel    the PESEL
     * @param phoneNum the phone number
     */
    public void printConfirmRegistration(String name,String lastName,String pesel,String phoneNum)
    {
        System.out.println("\n   Data you have entered:");
        System.out.println("Name: "+ name);
        System.out.println("Last name: "+ lastName);
        System.out.println("PESEL: "+ pesel);
        System.out.println("Phone number: "+ phoneNum);

        System.out.println("Select:");
        System.out.println("1 -> Confirm registration.");
        System.out.println("(Other key) -> Cancel registration");
    }

    /**
     * Print registration failed.
     */
    public void printRegistrationFailed()
    {
        System.out.println("Registration failed!\n");
    }

    /**
     * Print get id question.
     */
    public void printGetIdQuestion()
    {
        System.out.println("Enter id of your register:");
    }

    /**
     * Print get name view.
     */
    public void printGetNameView()
    {
        System.out.println("Enter your name:");
    }

    /**
     * Print get last name view.
     */
    public void printGetLastNameView()
    {
        System.out.println("Enter your last name:");
    }

    /**
     * Print get pesel view.
     */
    public void printGetPeselView()
    {
        System.out.println("Enter your pesel:");
    }

    /**
     * Print get phone number view.
     */
    public void printGetPhoneNumView()
    {
        System.out.println("Enter your phone number:");
    }

    /**
     * Print new registration view.
     */
    public void printNewRegistrationView()
    {
        System.out.println("\n\n\n\n\n\n\n");
        System.out.println("Now, you have to answear some questions:");
    }

    /**
     * Print first - main menu page.
     */
    public void printFirstPage()
    {
        System.out.println("Main menu of the Registration System");
        System.out.println("What would you like to do? Enter:");
        System.out.println("1 -> Make a register");
        System.out.println("2 -> Check register data");
        System.out.println("3 -> Check number of patients to selected doctor");
        System.out.println("9 -> Close");
    }

    /**
     * Print selection of doctor.
     */
    public void printDoctorSelectionView()
    {
        System.out.println("Choose the specialist that you want to go. Enter:");
        System.out.println("1. Dr Adam Smith - laryngologist");
        System.out.println("2. Dr Will Johnson - orthopedist");
        System.out.println("3. Dr Thomas Williams - internist");
        System.out.println("(Other key) Resign");
    }

    /**
     * Method to print doctors patient count
     * @param doctor doctor
     * @param count count of patients
     */
    public void printPatientsCount(Doctor doctor, int count)
    {
        System.out.println("Doctor " + doctor.toString() + "has " + count + " patients to take care of.\n");
    }

    /**
     * Instantiates a new Patient view.
     */
    public PatientView() {
        //empty constructor because we don't have to init any buttons or labels,
        // because of UI in console
    }



}
