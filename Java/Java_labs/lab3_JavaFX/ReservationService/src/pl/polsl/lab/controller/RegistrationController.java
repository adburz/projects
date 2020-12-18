package pl.polsl.lab.controller;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import pl.polsl.lab.ScenesController;
import pl.polsl.lab.model.PatientsList;
import pl.polsl.lab.utils.Doctor;
import pl.polsl.lab.view.PatientView;

/**
 * Controller class of Registration.fxml file.
 */
public class RegistrationController {

    /**
     *  Model class object.
     */
    private PatientsList model;

    /**
     *  View class object
     */
    private PatientView view;

    /**
     * ToggleGroup used to move radio buttons into group.
     */
    @FXML
    private ToggleGroup toggleGroup;
    /**
     * TextField used to enter name by user.
     */
    @FXML
    private TextField nameTextField;
    /**
     * TextField used to enter last name by user.
     */
    @FXML
    private TextField lastNameTextField;
    /**
     * TextField used to enter pesel by user.
     */
    @FXML
    private TextField peselTextField;
    /**
     * TextField used to enter phoneNumber by user.
     */
    @FXML
    private TextField phoneNumberTextField;

    /**
     * RadioButton used to choose Doctor by user.
     */
    @FXML
    private RadioButton JohnsonRadioButton;

    /**
     * RadioButton used to choose Doctor by user.
     */
    @FXML
    private RadioButton WilliamsRadioButton;

    /**
     * Default constructor.
     */
    public RegistrationController(){
        this.model = null;
        this.view = null;

        toggleGroup = new ToggleGroup();
    }

    /**
     * Model setter.
     * @param model model to set.
     */
    public void setModel(PatientsList model) {
        this.model = model;
    }

    /**
     * View setter
     * @param view view to set.
     */
    public void setView(PatientView view) {
        this.view = view;
    }

    /**
     * Method used by registerButton from .fxml frontend. Used to try to register new patient.
     * @param actionEvent event
     */
    public void registerButton_click(ActionEvent actionEvent) {
        String name = nameTextField.getText();
        String lastName = lastNameTextField.getText();
        String pesel = peselTextField.getText();
        String phoneNum = phoneNumberTextField.getText();
        Doctor doctor = readDoctor();
        try{
            int new_id = model.addPatient(name, lastName, pesel, phoneNum, doctor);
            new Alert(Alert.AlertType.INFORMATION,
                    "Successfully registered!\nID: "+Integer.toString(new_id)).showAndWait();
        }
        catch (Exception e)
        {
            new Alert(Alert.AlertType.ERROR, e.getMessage()).showAndWait();
        }

    }

    /**
     * Method used to read from toggleGroup checked doctor type.
     * @return chosen doctor
     */
    private Doctor readDoctor(){
        if(toggleGroup.getSelectedToggle() == JohnsonRadioButton)
        {
            return Doctor.Johnson;
        }
        else if(toggleGroup.getSelectedToggle() == WilliamsRadioButton){
            return Doctor.Williams;
        }
        else{
            return Doctor.Smith;
        }
    }

    /**
     * Method used by toMeinMenuButton button from .fxml file. Used to get back into main menu.
     * @param e event
     */
    @FXML
    private void toMainMenuButton_click(ActionEvent e) {
        ScenesController.setScenes(ProgramTypeController.class);
        ScenesController.getController(ProgramTypeController.class).setModel(model);
        ScenesController.getController(ProgramTypeController.class).setView(view);
    }

}
