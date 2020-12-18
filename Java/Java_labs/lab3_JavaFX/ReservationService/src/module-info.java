/**
 * module-info.java file.
 */
module ReservationService {
    requires javafx.graphics;
    requires javafx.fxml;
    requires javafx.controls;
    requires jdk.jfr;
    requires org.junit.jupiter.api;
    requires org.junit.jupiter.params;

    exports pl.polsl.lab.controller to javafx.fxml;
    exports pl.polsl.lab to javafx.fxml;
    opens pl.polsl.lab;
    opens pl.polsl.lab.controller;
    opens pl.polsl.lab.model to javafx.base;

}