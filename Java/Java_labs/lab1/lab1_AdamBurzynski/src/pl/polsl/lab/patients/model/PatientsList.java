package pl.polsl.lab.patients.model;


import pl.polsl.lab.patients.exceptions.PatientParamsException;

import java.io.*;
import java.util.*;

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
        return (name.matches("[a-zA-Z ]*"));
    }

    /**
     * Method used to check if phone number contains only decimals and a plus (when +48 or some else)
     * @param phoneNum String parameter to validate
     * @return true or false, depends on .matches method
     */
    private boolean phoneNumValidation(String phoneNum)
    {
        return (phoneNum.matches("[^0-9+]*"));
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
     * Instantiates a new Patients list.
     *
     * @param dbPath path to data base file with serialized data about patients.
     */
    public PatientsList(String dbPath) {
        loadModelData(dbPath);
    }

    /**
     * Method used to add new patient into list. Method can throw an exception which informs user which parameter is in wrong format.
     *
     * @param name        name of new user.
     * @param lastName    last name of user.
     * @param pesel       PESEL of user.
     * @param phoneNumber phone number of user.
     * @return method returns id of new added user for controller, to pass it into view to print it for user.
     * @throws PatientParamsException exception which informs user which parameter (name/last name/PESEL/phone number) was wrong.
     */
    public Integer addPatient(String name, String lastName, String pesel, String phoneNumber) throws PatientParamsException {
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
            else  if (phoneNumValidation(phoneNumber)) {
                throw new PatientParamsException("Typed phone number is not correct.");
            }


        Patient new_patient = new Patient(name, lastName, pesel, phoneNumber, new_id);
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
     * Method used to deserialise data from file passed by console arguments.
     *
     * @param filePath path to data base file. If its null, array will be also null.
     */
    public void loadModelData(String filePath)
    {
        patients = new ArrayList<>();
        if(filePath!=null) {
            try {
                FileInputStream file = new FileInputStream(filePath);
                ObjectInputStream in = new ObjectInputStream(file);

                patients = (ArrayList) in.readObject();
                file.close();
                in.close();

            } catch (Exception e) {
                System.err.println(e);
            }
        }
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
