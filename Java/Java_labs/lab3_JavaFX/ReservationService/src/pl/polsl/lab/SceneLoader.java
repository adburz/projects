package pl.polsl.lab;

import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;

import java.io.IOException;
import java.net.URL;

/**
 * Generic type class used to contain scenes
 * @param <TController> generic constructor class type
 */
public class SceneLoader<TController> {
    /**
     * Path to .fxml file.
     */
    private String path;
    /**
     * Current set scene.
     */
    private Scene scene;

    /**
     * Fxml loader
     */
    private FXMLLoader loader;

    /**
     * Constructor of class
     * @param path path to fxml file
     * @throws IOException IOexception
     */
    public SceneLoader(String path) throws IOException {
        this.path = path;

        URL url = getClass().getResource(path);
        loader = new FXMLLoader(url);
        Parent root = loader.load();
        scene = new Scene(root, 400, 400);

    }

    /**
     * Getter of loader controller.
     * @return loader controller
     */
    public TController getController(){
        return loader.getController();
    }

    /**
     * Scene getter.
     * @return current scene.
     */
    public Scene getScene(){
        return scene;
    }
}
