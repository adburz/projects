package pl.polsl.lab;

/**
 * Application for creating reservations by patients.
 *
 * @author Adam Burzynski
 * @version 1.0.0
 */
public class Main{

    /**
     * Main.
     *
     * @param args array of string which contains main arguments. In this case, we want to pass .txt file where data will be saved.
     */
    public static void main(String[] args) {
        if (args.length == 0)  /**when user didnt pass any arguments, the data wont be saved and also wont be loaded.*/ {
            System.out.println("Program started without params");
        } else {
            System.out.println("Program started with params");
        }

        ScenesController scenesController = new ScenesController();
        scenesController.run();


    }

}
