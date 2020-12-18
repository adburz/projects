package pl.polsl.lab.exceptions;


/**
 * The type Patient params exception.
 * @version 1.0
 */
public class PatientParamsException extends Exception{
    /**
     * String used to clear output formats.
     */
    private final String ANSI_RESET = "\u001B[0m";
    /**
     * String used to color output message red.
     */
    private final String ANSI_RED = "\u001B[31m";
    /**
     * It contains message about exception.
     */
    private String msg;

    /**
     * Instantiates a new Patient params exception.
     *
     * @param message the message
     */
    public PatientParamsException(String message)
{
    super(message);
    msg = message;
}

    /**
     * Print error message.
     */
    public void PrintErrorMessage()
{
    System.out.println(ANSI_RED + msg + ANSI_RESET);
}


}
