package pl.polsl.lab.model;


import pl.polsl.lab.exceptions.PatientParamsException;
import pl.polsl.lab.utils.Doctor;

import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

/**
 * Represents model structure of MVC, which contains list of registered patients, loaded from file used with serialization.
 * @version 1.0
 */
public class PatientsList {

    /**
     * List of registered patients.
     */
    private List<Patient> patients;

    /**
     * Method used to check if name contains only letters and spaces.
     * @param name String parameter to validate
     * @return true or false, depends on .matches method
     */
    private boolean nameValidation(String name)
    {
        if(name.matches("[a-zA-Z ]*") && name.length() < 40)    /**name and last name should be shorter than 40 signs*/
            return true;
        return false;
    }

    /**
     * Method used to check if phone number contains only decimals and a plus (when +48 or some else)
     * @param phoneNum String parameter to validate
     * @return true or false, depends on .matches method
     */
    private boolean phoneNumValidation(String phoneNum)
    {
        if(phoneNum.matches("[0-9+ ]*") && phoneNum.length() < 18 && phoneNum.length() >= 6)
            return true;
        return false;
    }

    /**
     * Method used to check if PESEL contains only decimals, has length of 11, and also fulfills checking algorithm.
     * @param pesel String parameter to validate
     * @return true or false, depends on .matches method
     */
    private boolean peselValidation(String pesel)
    {
        //using regex to check if pesel length is 11 and if it contains only numbers
        if(pesel.length() != 11 || !pesel.matches("[0-9]*"))
            return false;
        else
        {

            //convering string with PESEL into int array
            int pTab[] = new int[11];
            for(int i=0; i<11; i++)
            {
                pTab[i] = pesel.charAt(i) - '0';
            }

            //begining of the validation algorithm
            int sum = 0;
            int tmp;
            for (int i = 0; i < 9; i += 4)	//summing of '1' scales
            {
                tmp = pTab[i] * 1;			//tmp - the result of multiplication given element and the scales
                if (tmp - 10 < 0)			//if a digit number
                {
                    sum += tmp;
                    continue;
                }
                else						//if dwo-digit number
                {
                    tmp = tmp % 10;
                    sum += tmp;
                }
            }

            for (int i = 1; i < 10; i += 4)	//summing of '3' scales
            {
                tmp = pTab[i] * 3;
                if (tmp - 10 < 0)
                {
                    sum += tmp;
                    continue;
                }
                else						//if dwo-digit number
                {
                    tmp = tmp % 10;
                    sum += tmp;
                }
            }

            for (int i = 2; i < 7; i += 4)	//summing of '7' scales
            {
                tmp = pTab[i] * 7;
                if (tmp - 10 < 0)
                {
                    sum += tmp;
                    continue;
                }
                else						//if dwo-digit number
                {
                    tmp = tmp % 10;
                    sum += tmp;
                }
            }
            for (int i = 3; i < 8; i += 4)	//summing of '9' scales
            {
                tmp = pTab[i] * 9;
                if (tmp - 10 < 0)
                {
                    sum += tmp;
                    continue;
                }
                else						//if dwo-digit number
                {
                    tmp = tmp % 10;
                    sum += tmp;
                }
            }
            sum = sum % 10;
            int controlSum = 10 - sum;

            if(pTab[10] == controlSum)
                return true;
            return false;

        }
    }

    /**
     * Method used to return id for new user.
     * @return returns id for new user.
     */
    private Integer getNewId()
    {
        if(patients.isEmpty())
        {
            return 1;
        }
        else
        {
            return patients.get(patients.size() - 1).getId() + 1;
        }
    }

    /**
     * Default constructor.
     */
    public PatientsList(){
        patients = new ArrayList<>();
    }
    /**
     * Constructor deserialise data from file passed by console arguments.
     *
     * @param dbPath path to data base file. If its null, array will be also null.
     */
    public PatientsList(String dbPath) {
        patients = new ArrayList<>();
        if(dbPath!=null) {
            try {
                FileInputStream file = new FileInputStream(dbPath);
                ObjectInputStream in = new ObjectInputStream(file);

                patients = (ArrayList) in.readObject();
                file.close();
                in.close();

            } catch (Exception e) {
                patients = null;
                System.err.println(e);
            }
        }
    }

    /**
     * Method that returns list of chosen patients by doctor type
     * @param doctor doctor type
     * @return list which contains patients
     */
    public List<Patient> getChosenPatients(Doctor doctor)
    {
        List<Patient> tmpPatientList = patients
                .stream()
                .filter(c -> ( c.getDoctor() == doctor))
                .collect(Collectors.toList());

        return tmpPatientList;
    }

    /**
     * Method that returns number of patients of the chosen doctor
     * @param doctor chosen doctor
     * @return  number of patients assigned to doctor
     */
    public int getPatientsCount(Doctor doctor)
    {
        List<Patient> tmpPatientList = patients
                .stream()
                .filter(c -> ( c.getDoctor() == doctor))
                .collect(Collectors.toList());

        return tmpPatientList.size();

    }
    /**
     * Method used to add new patient into list. Method can throw an exception which informs user which parameter is in wrong format.
     *
     * @param name        name of new user.
     * @param lastName    last name of user.
     * @param pesel       PESEL of user.
     * @param phoneNumber phone number of user.
     * @param doctor      doctor to whom the patient is registerd
     * @return method returns id of new added user for controller, to pass it into view to print it for user.
     * @throws PatientParamsException exception which informs user which parameter (name/last name/PESEL/phone number) was wrong.
     */
    public Integer addPatient(String name, String lastName, String pesel, String phoneNumber, Doctor doctor) throws PatientParamsException {

            Integer new_id = getNewId();

            if (!nameValidation(name)) {
                throw new PatientParamsException("Typed name is in wrong format.");
            }
            else if (!nameValidation(lastName)) {
                throw new PatientParamsException("Typed last name is in wrong format.");
            }
            else if (!peselValidation(pesel)) {
                throw new PatientParamsException("Typed PESEL is not correct.");
            }
            else  if (!phoneNumValidation(phoneNumber)) {
                throw new PatientParamsException("Typed phone number is not correct.");
            }

        Patient new_patient = new Patient(name, lastName, pesel, phoneNumber, new_id, new Date(), doctor);
        patients.add(new_patient);
        return new_id;
    }

    /**
     * Method used to return patient from list to controller for print its data (name/last name/PESEL/phone number) on the console.
     *
     * @param _id id of wanted user
     * @return Patient object
     */
    public Patient getInfoById(int _id)
    {
        for(Patient p : patients)
        {
            if(p.getId() == _id)
            {
                return p;
            }
        }
        return null;
    }

    /**
     * Method used to serialize data to data base file.
     *
     * @param filePath path to data base file. If its null, data will not be saved.
     */
    public void saveModelData(String filePath)
    {
        if(filePath!=null)
        {
            try{
            FileOutputStream fos = new FileOutputStream(filePath);
            ObjectOutputStream oos = new ObjectOutputStream(fos);
            oos.writeObject(patients);
            oos.close();
            fos.close();
            }
            catch(Exception e)
            {
                System.err.println(e);
            }
        }
    }
}
