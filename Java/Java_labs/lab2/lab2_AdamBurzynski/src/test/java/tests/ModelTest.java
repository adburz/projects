package tests;

import org.junit.jupiter.api.*;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.EnumSource;
import org.junit.jupiter.params.provider.ValueSource;
import pl.polsl.lab.patients.exceptions.PatientParamsException;
import pl.polsl.lab.patients.utils.Doctor;
import pl.polsl.lab.patients.model.Patient;
import pl.polsl.lab.patients.model.PatientsList;


import static org.junit.jupiter.api.Assertions.fail;
import static org.junit.jupiter.api.Assertions.*;

/**
 * Class used to make tests.
 */
public class ModelTest {

    /**
     * Model - PatientsList class.
     */
    PatientsList model;

    /**
     * Constructor
     */
    public ModelTest() {
    }

    /**
     * Method used before each test.
     */
    @BeforeEach
    public void InitialModelTest() {
        model = new PatientsList(null); //adding empty parameter
    }

    /**
     * Method used after each test.
     */
    @AfterEach
    public void FreeModelTest() {
        model = null;
    }

    /**
     * Method used to check if the constructor works properly.
     */
    @Test
    public void testModelConstructor() {
        try {
            model = new PatientsList(null);
            model = null;
            model = new PatientsList("C:\\Users\\Adam\\Desktop\\java_db.txt");
            model = null;
            model = new PatientsList("adasdasdasd");
        }
        catch(Exception e)
        {
        }
    }
    /**
     * Patametrized test to check if the addPatient function will throw an exception caused wrong name.
     *
     * @param name name of the patient
     */
    @ParameterizedTest
    @ValueSource(strings = {"Kuba1", "Kuba_"})
    public void testEnteringWrongName(String name) {
        try {
            model.addPatient(name, "Nitecki", "00121539724", "123123123", Doctor.Johnson);
            fail("Name with not allowed sign was added without exception throw.");
        } catch (PatientParamsException e) {

        }
    }

    /**
     * Parametrized test used to check if the proper values are adding properly.
     *
     * @param name name of the patient.
     */
    @ParameterizedTest
    @ValueSource(strings = {"Kuba", "Miłosz", "Wiktor"})
    public void testEnteringProperlyName(String name) {

        model = new PatientsList(null);
        try {
            model.addPatient(name, "Nitecki", "00121539724", "123123123", Doctor.Johnson);
            assertEquals(model.getInfoById(1).getFirstname(), name);
            model = null;
        } catch (PatientParamsException e) {

        }
    }

    /**
     * Patametrized test to check if the addPatient function will throw an exception caused wrong last name.
     *
     * @param lastName last name of the patient
     */
    @ParameterizedTest
    @ValueSource(strings = {"Nitecki1", "Nitecki)"})
    public void testEnteringWrongLastName(String lastName) {
        try {
            model.addPatient("Kuba", lastName, "00121539724", "123123123", Doctor.Johnson);
            fail("Last name with not allowed sign was added without exception throw.");
        } catch (PatientParamsException e) {

        }
    }

    /**
     * Parametrized test used to check if the proper values are adding properly.
     *
     * @param lastName name of the patient.
     */
    @ParameterizedTest
    @ValueSource(strings = {"Tropik", "Packa", "Wichajster"})
    public void testEnteringProperlyLastName(String lastName) {

        model = new PatientsList(null);
        try {
            model.addPatient("Dawid", lastName, "00121539724", "123123123", Doctor.Johnson);
            assertEquals(model.getInfoById(1).getLastname(), lastName);
            model = null;
        } catch (PatientParamsException e) {

        }
    }

    /**
     * Test used to check if the addPatient method will throw an exception coused wrong PESEL
     *
     * @param pesel wrong PESEL to test
     */
    @ParameterizedTest
    @ValueSource(strings = {"12312312312", "123", "123123123123123123123123123"})
    public void testEnteringWrongPESEL(String pesel) {
        try {
            model.addPatient("Kuba", "Nitecki", pesel, "123123123", Doctor.Johnson);
            fail("Wrong PESEL was added without exception throw.");
        } catch (PatientParamsException e) {

        }
    }

    /**
     * Test to check if the addPatient method will correctly add patient with properly PESEL.
     *
     * @param pesel properly pesel.
     */
    @ParameterizedTest
    @ValueSource(strings = {"85081994497", "19312735294", "45022040256"})
    public void testEnteringProperPESEL(String pesel) {
        model = new PatientsList(null);
        try {
            model.addPatient("Kuba", "Nitecki", pesel, "123123123", Doctor.Johnson);
            assertEquals(model.getInfoById(1).getPesel(), pesel);
            model = null;
        } catch (PatientParamsException e) {

        }
    }

    /**
     * Test to check if addPatient method will throw exception when adding patient with wrong phone number format.
     *
     * @param phoneNum phone number to add
     */
    @ParameterizedTest
    @ValueSource(strings = {"123123123a", "12345", "asdasd"})
    public void testEnteringWrongPhoneNum(String phoneNum) {
        try {
            model.addPatient("Kuba", "Nitecki", "00121539724", phoneNum, Doctor.Johnson);
            fail("Wrong phone number was added without exception throw.");
        } catch (PatientParamsException e) {

        }
    }

    /**
     * Test to check if addPatient method will throw exception when adding patient with correct phone number format.
     *
     * @param phoneNum phone number to add
     */
    @ParameterizedTest
    @ValueSource(strings = {"+48 333 222 111", "123123123"})
    public void testEnteringProperPhoneNum(String phoneNum) {
        model = new PatientsList(null);
        try {
            model.addPatient("Kuba", "Nitecki", "00121539724", phoneNum, Doctor.Johnson);
            assertEquals(model.getInfoById(1).getPhoneNum(), phoneNum);
            model = null;
        } catch (PatientParamsException e) {

        }
    }

    /**
     * Test used to check if the getPatientsCount works properly, ale returns provided value.
     */
    @Test
    public void testGetPatientsNotNullCount() {
        model = new PatientsList(null);
        try {
            model.addPatient("n", "ln", "00121539724", "123123123", Doctor.Johnson);
            model.addPatient("n", "ln", "00121539724", "123123123", Doctor.Johnson);

            model.addPatient("n", "ln", "00121539724", "123123123", Doctor.Smith);

            /** Not adding any registration for Williams */

            assertEquals(model.getPatientsCount(Doctor.Johnson), 2);
            assertEquals(model.getPatientsCount(Doctor.Smith), 1);
            assertEquals(model.getPatientsCount(Doctor.Williams), 0);
        } catch (PatientParamsException e) {

        }
    }

    /**
     * Test used to check if the getPatientsCount method returns 0 patients count if the list is empty.
     */
    @Test
    public void testGetPatientsNullCount() {
        model = new PatientsList(null);

        assertEquals(model.getPatientsCount(Doctor.Johnson), 0);
        assertEquals(model.getPatientsCount(Doctor.Smith), 0);
        assertEquals(model.getPatientsCount(Doctor.Williams), 0);

    }

    /**
     * Parametrized test to check if the getPatientsCount works properly with adding 3 patients to the other - parametrized doctors.
     *
     * @param doctor doctor used to add.
     */
    @ParameterizedTest
    @EnumSource(Doctor.class)
    public void testGetPatientsCount(Doctor doctor) {
        model = new PatientsList(null);
        try {
            model.addPatient("n", "ln", "00121539724", "123123123", doctor);
            model.addPatient("n", "ln", "00121539724", "123123123", doctor);
            model.addPatient("n", "ln", "00121539724", "123123123", doctor);

            assertEquals(model.getPatientsCount(doctor), 3);
        } catch (PatientParamsException e) {
        }
    }

    /**
     * Test to check if the getInfoById method returns null, when array is null.
     */
    @Test
    public void testGetInfoByIdFromEmptyArray() {
        Patient p = model.getInfoById(0);
        assertEquals(null, p);
    }

    /**
     * Test to check if getInfoById returns null, when id is wrong.
     */
    @Test
    public void testGetInfoNull() {
        try {
            model.addPatient("Name", "LastName", "00121539724", "123123123", Doctor.Johnson);
            Patient p = model.getInfoById(0);
            assertEquals(null, p);
        } catch (PatientParamsException e) {
        }
    }
}

