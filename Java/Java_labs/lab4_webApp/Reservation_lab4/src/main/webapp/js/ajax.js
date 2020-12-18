function openRegistration(){
    window.location.href="../Reservation_lab4_war_exploded/registration.html";
}

function openStartPage(){
    window.location.href="../Reservation_lab4_war_exploded/index.html";
}

function openCheckRegistration(){
    window.location.href="../Reservation_lab4_war_exploded/checkRegistration.html";
}

function openPatientsQueue(){
    window.location.href="../Reservation_lab4_war_exploded/patientsQueue.html";
}

function loadCookies(){
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function() {
        document.getElementById('patientTable').innerHTML = this.responseText;
    }

    xhttp.open("GET",
        "patientsQueue?doctorName="+doctorName, true);
    xhttp.send();
}

function loadPatientsTable(doctorName){

    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function() {
        document.getElementById('patientTable').innerHTML = this.responseText;
    }

    xhttp.open("GET",
        "patientsQueue?doctorName="+doctorName, true);
    xhttp.send();
}

function findRegistration(regId){
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function() {
                document.getElementById('info').innerHTML = this.responseText;
        }

    let ar1 = document.getElementById(regId).value;
    if(!/^[0-9]+$/g.test(ar1)){
        alert("Registration ID should be number!")
        xhttp.abort();
        return
    }

    xhttp.open("GET",
        "checkRegistration?regId="+ar1, true);
    xhttp.send();
}



function tryRegistration(name, lastName, pesel, phoneNumber, doctor){
        var xhttp = new XMLHttpRequest();
        var errors = ["Typed name is in wrong format.", "Typed last name is in wrong format.",
            "Typed PESEL is not correct.", "Typed phone number is not correct.", "Successfully registered!"];


    xhttp.onreadystatechange = function() {
        //if(errors.includes(this.responseText)) {
            alert(this.getResponseHeader("myMessage"))
        //}
    }


    let ar1 = document.getElementById(name).value;
    if(!/^[a-zA-Z ]+$/g.test(ar1)){
        alert("Please enter first name in correct format!")
        xhttp.abort();
        return
    }

    let ar2 = document.getElementById(lastName).value;
    if(!/^[a-zA-Z ]+$/.test(ar2)){
        alert("Please enter last name in correct format!")
        xhttp.abort();
        return
    }

    let ar3 = document.getElementById(pesel).value;
    if(!/^[0-9]+$/.test(ar3)){
        alert("Please enter pesel in correct format!")
        xhttp.abort();
        return
    }
    let ar4 = document.getElementById(phoneNumber).value;
    if(!/^[0-9+ ]+$/.test(ar4)){
        alert("Please enter phone number in correct format!")
        xhttp.abort();
        return
    }

    let combo = document.getElementById(doctor);
    let ar5 = combo.options[combo.selectedIndex].value;

    xhttp.open("GET",
        "register?firstName=" + ar1
        + "&lastName=" + ar2
        + "&pesel=" + ar3
        + "&phoneNumber=" + ar4
        + "&doctor=" + ar5, true);
    xhttp.send();
}