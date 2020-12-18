package pl.polsl.lab.patients.model;

/**
 * The type Patient.
 * @version 1.0
 */
public class Patient implements java.io.Serializable {
    /**
     * First name of patient.
     */
    private String firstName;
    /**
     * Last name of patient.
     */
    private String lastName;
    /**
     * PESEL of patient, which is the netional identification number used in Poland.
     */
    private String pesel;
    /**
     * Phone number of patient.
     */
    private String phoneNum;
    /**
     * ID of patient
     */
    private Integer id;

    /**
     * Instantiates a new Patient.
     *
     * @param firstName the first name
     * @param lastName  the last name
     * @param PESEL     the pesel
     * @param phoneNum  the phone num
     * @param id        the id
     */
    public Patient(String firstName, String lastName, String PESEL, String phoneNum, Integer id) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.pesel = PESEL;
        this.phoneNum = phoneNum;
        this.id = id;
    }

    /**
     * Gets pesel.
     *
     * @return the pesel
     */
    public String getPesel() {
        return pesel;
    }

    /**
     * Gets id.
     *
     * @return the id
     */
    public Integer getId() {
        return id;
    }

    /**
     * Gets firstname.
     *
     * @return the firstname
     */
    public String getFirstname() {
        return firstName;
    }

    /**
     * Gets lastname.
     *
     * @return the lastname
     */
    public String getLastname() {
        return lastName;
    }

    /**
     * Gets phoneNum.
     *
     * @return the phoneNum
     */
    public String getPhoneNum() {
        return phoneNum;
    }


}
