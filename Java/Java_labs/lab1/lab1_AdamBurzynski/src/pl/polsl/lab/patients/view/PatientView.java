package pl.polsl.lab.patients.view;


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
     */
    public void printRegInfo(String name, String lastName, String pesel, String phoneNum)
    {
        System.out.println("\n   Registration data:");
        System.out.println("Name: "+ name);
        System.out.println("Last name: "+ lastName);
        System.out.println("PESEL: "+ pesel);
        System.out.println("Phone number: "+ phoneNum);
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
        System.out.println("2 -> Check register date");
        System.out.println("9 -> Close");
    }

    /**
     * Instantiates a new Patient view.
     */
    public PatientView() {
        //empty constructor because we don't have to init any buttons or labels,
        // because of UI in console
    }



}
