package pl.polsl.lab.controller;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import pl.polsl.lab.ScenesController;
import pl.polsl.lab.model.Patient;
import pl.polsl.lab.model.PatientsList;
import pl.polsl.lab.view.PatientView;

/**
 * Controller class of CheckRegistration .fxml scene.
 */
public class CheckRegistrationController {

    /**
     * idTextField .fxml field.
     */
    @FXML
    private TextField idTextField;

    /**
     * textArea .fxml field.
     */
    @FXML
    private TextArea textArea;

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
     * Model class object.
     */
    private PatientsList model;

    /**
     * View class object
     */
    private PatientView view;

    /**
     * Default constructor.
     */
    public CheckRegistrationController(){
        model = null;
        view = null;
    }

    /**
     * Method used by FindButton from .fxml frontend. Used to triger finding operation.
     * @param e event
     */
    @FXML
    private void FindButton_click(ActionEvent e){
        int id = Integer.parseInt(idTextField.getText().isEmpty() ? "0" : idTextField.getText() );
        Patient info = model.getInfoById(id);

        if(info != null) {
            String text = "Registration data:\n" + "Name: " + info.getFirstName() +
                    "\nLast name: " + info.getLastName() + "\nPESEL: "+ info.getPesel()+
                    "\nPhone number: " + info.getPhoneNum() + "\nDate: " + info.getDate() +
                    "\nDoctor: " + info.getDoctor().toString();
            textArea.setText(text);
        }
        else
        {
            textArea.setText("Patient with this ID doesnt exists!");
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
