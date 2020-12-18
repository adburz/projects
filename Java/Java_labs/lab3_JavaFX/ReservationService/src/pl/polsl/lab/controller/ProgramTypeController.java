package pl.polsl.lab.controller;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import pl.polsl.lab.ScenesController;
import pl.polsl.lab.model.PatientsList;
import pl.polsl.lab.view.PatientView;

/**
 * Controller class of ProgramType .fxml scene.
 */
public class ProgramTypeController {

    /**
     * Model class object.
     */
    private PatientsList model;

    /**
     * View class object
     */
    private PatientView view;

    /**
     * Method used by registerModuleButton from .fxml frontend. Used to change front scene.
     * @param e event
     */
    @FXML
    private void registerModuleButton_click(ActionEvent e) {
        ScenesController.setScenes(RegistrationController.class);

        ScenesController.getController(RegistrationController.class).setModel(model);
        ScenesController.getController(RegistrationController.class).setView(view);
    }

    /**
     * Method used by setPatientsNumber from .fxml frontend. Used to change front scene.
     * @param e event
     */
    @FXML
    private void setPatientsNumber_click(ActionEvent e) {
        if(model==null){System.out.println("dupa");}
        ScenesController.setScenes(PatientsCountController.class);
        ScenesController.getController(PatientsCountController.class).setModel(model);
        ScenesController.getController(PatientsCountController.class).setView(view);
    }

    /**
     * Method used by setCloseButton from .fxml frontend. Used to close application.
     * @param e event
     */
    @FXML
    private void setCloseButton_click(ActionEvent e) {
        ScenesController.getStage().close();
    }

    /**
     * Method used by checkRegistrationModuleButton from .fxml frontend. Used to change front scene.
     * @param e event
     */
    @FXML
    private void checkRegistrationModuleButton_click(ActionEvent e) {
        ScenesController.setScenes(CheckRegistrationController.class);
        ScenesController.getController(CheckRegistrationController.class).setModel(model);
        ScenesController.getController(CheckRegistrationController.class).setView(view);
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
}
