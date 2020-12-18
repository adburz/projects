package pl.polsl.lab.patients.model;

import pl.polsl.lab.patients.utils.Doctor;

import java.util.Date;

/**
 * The type Patient.
 * @version 1.0
 * @version 2.0 added Date and Doctor fields.
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
     * Date of registration. It is the date on which the registration was submitted.
     */
    private Date date;

    /**
     * Specialist to whom the patient is registered
     */
    private Doctor doctor;

    /**
     * Instantiates a new Patient.
     *
     * @param firstName the first name
     * @param lastName  the last name
     * @param PESEL     the pesel
     * @param phoneNum  the phone num
     * @param date      date of the registration
     * @param id        the id
     * @param doctor    the doctor
     */
    public Patient(String firstName, String lastName, String PESEL, String phoneNum, Integer id, Date date, Doctor doctor) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.pesel = PESEL;
        this.phoneNum = phoneNum;
        this.id = id;
        this.date = date;
        this.doctor = doctor;
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

    /**
     * Gets registration date.
     * @return  registration date.
     */
    public Date getDate() {
        return date;
    }

    /**
     * Gets doctors name
     * @return returns chosen doctor
     */
    public Doctor getDoctor() {
        return doctor;
    }

}
