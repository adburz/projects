package pl.polsl.lab;

import javafx.application.Application;
import javafx.stage.Stage;
import pl.polsl.lab.controller.*;

import java.util.HashMap;
import java.util.Map;

/**
 * Class used to contain JavaFXs stage and scenes. This class contains application scenes in a Map data structure.
 * Class extends Application class.
 */
public class ScenesController extends Application {

    /**
     * Main stage of the project.
     */
    private static Stage stage;
    /**
     * Map container which contains frontend scenes.
     */
    private static Map<Class<?>, SceneLoader> scenes = new HashMap<>();
    /**
     * Main controller.
     */
    private static PatientController mainController;

    /**
     * Method used to run javaFX application.
     */
    public void run() {
        mainController = new PatientController();
        try {
            launch();
        } catch (Exception e) {
            System.err.println(e);
        }
    }

    /**
     * Method used by launch() method, which define the stage etc. It can be knows as constructor of javaFX application.
     * @param primaryStage primary stage of the application.
     * @throws Exception exception.
     */
    @Override
    public void start(Stage primaryStage) throws Exception {
        stage = primaryStage;

        scenes.put(ProgramTypeController.class, new SceneLoader<ProgramTypeController>("/ProgramType.fxml"));
        scenes.put(RegistrationController.class, new SceneLoader<RegistrationController>("/Registration.fxml"));
        scenes.put(PatientsCountController.class, new SceneLoader<PatientsCountController>("/PatientsCount.fxml"));
        scenes.put(CheckRegistrationController.class, new SceneLoader<CheckRegistrationController>("/CheckRegistration.fxml"));


        mainController.run();

        primaryStage.setTitle("Registration System");
    }

    /**
     * Stage getter.
     * @return stage
     */
    public static Stage getStage() {
        return stage;
    }

    /**
     * Method used to set scene
     * @param classType generic type class
     * @param <T> generic type
     */
    public static <T> void setScenes(Class<T> classType) {
        stage.setScene(scenes.get(classType).getScene());
        stage.show();
    }

    /**
     *
     * @param classType generic class type of controller
     * @param <T> generic type controller class
     * @return controller of current scene
     */
    public static <T> T getController(Class<T> classType) {
        return (T) scenes.get(classType).getController();
    }


}
