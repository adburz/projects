package pl.polsl.lab.controller;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import pl.polsl.lab.ScenesController;
import pl.polsl.lab.model.Patient;
import pl.polsl.lab.model.PatientsList;
import pl.polsl.lab.utils.Doctor;
import pl.polsl.lab.view.PatientView;

import java.util.ArrayList;
import java.util.List;

/**
 * Controller class of PatientsCount.fxml file.
 */
public class PatientsCountController {
    /**
     * Model class object.
     */
    private PatientsList model;

    /**
     * View class object
     */
    private PatientView view;

    /**
     * Label used to print patients count.
     */
    @FXML
    private Label patientCountLabel;

    /**
     * TableView property.
     */
    @FXML
    private TableView table;
    /**
     * TableColumn property.
     */
    @FXML
    private TableColumn Name;
    /**
     * TableColumn property.
     */
    @FXML
    private TableColumn LastName;
    /**
     * TableColumn property.
     */
    @FXML
    private TableColumn PhoneNumber;

    /**
     * ObservableList type of Patient to contain Patients.
     */
    ObservableList<Patient> data = FXCollections.observableArrayList();;

    /**
     * Default constructor.
     */
    public void PatientsCountController(){
        model = null;
        view = null;
    }

    /**
     * Method used to initialise TableView.
     */
    @FXML
    public void initialize(){
        table.setItems(data);

        Name.setCellValueFactory(new PropertyValueFactory<Patient,String>("firstName"));
        LastName.setCellValueFactory(new PropertyValueFactory<Patient,String>("lastName"));
        PhoneNumber.setCellValueFactory(new PropertyValueFactory<Patient,String>("phoneNum"));
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
     * Method used by SmithButton button when onAction. It triggers getPatientsCount mathod and sets TableView content.
     */
    @FXML
    private void SmithButton_click(){
        patientCountLabel.setText(Integer.toString(model.getPatientsCount(Doctor.Smith)));

        data = FXCollections.observableArrayList(model.getChosenPatients(Doctor.Smith));
        table.setItems(data);
    }
    /**
     * Method used by JohnsonButton button when onAction. It triggers getPatientsCount mathod and sets TableView content.
     */
    @FXML
    private void JohnsonButton_click(){
        patientCountLabel.setText(Integer.toString(model.getPatientsCount(Doctor.Johnson)));

        data = FXCollections.observableArrayList(model.getChosenPatients(Doctor.Johnson));
        table.setItems(data);
    }
    /**
     * Method used by WilliamsButton button when onAction. It triggers getPatientsCount mathod and sets TableView content.
     */
    @FXML
    private void WilliamsButton_click(){
        patientCountLabel.setText(Integer.toString(model.getPatientsCount(Doctor.Williams)));

        data = FXCollections.observableArrayList(model.getChosenPatients(Doctor.Williams));
        table.setItems(data);
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
