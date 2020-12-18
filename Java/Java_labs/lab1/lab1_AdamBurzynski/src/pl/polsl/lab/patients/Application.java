package pl.polsl.lab.patients;

import pl.polsl.lab.patients.controller.PatientController;

/**
 * Application for creating reservations by patients.
 *
 * @author Adam Burzynski
 * @version 1.0.0
 */
public class Application {

    /**
     * Main.
     *
     * @param args array of string which contains main arguments. In this case, we want to pass .txt file where data will be saved.
     */
    public static void main(String args[])
    {

    if(args.length==0)  /**when user didnt pass any arguments, the data wont be saved and also wont be loaded.*/
    {
        PatientController controller = new PatientController(null);
        controller.initController();
    }
    else
    {
        PatientController controller = new PatientController(args[0]);
        controller.initController();
    }

    return;
    }

}
