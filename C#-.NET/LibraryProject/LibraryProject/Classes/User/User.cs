using System;
using System.Collections.Generic;
using System.Diagnostics;

namespace LibraryProject.Classes.UserClass
{
    [Serializable()]
    public enum ERole
    {
        Client ,
        Admin
    }
    public class User
    {
        public ERole Role;
        public List<Notification> Notifications { get; set; }
        public string SRole { get; set; } = "empty";
        public string Login { get; set; } = "empty";
        public string Password { get; set; } = "empty";
        public string Name { get; set; } = "empty";
        public string Surname { get; set; } = "empty";
        public string Pesel { get; set; } = "empty";
        public string Email { get; set; } = "empty";
        public uint HireCount { get; set; } = 0;
        public uint ExpiredCount { get; set; } = 0;
        public uint UserID { get; set; } = 0;
        public string PhoneNumber { get; set; } = "empty";
        

        public User(string _login, string _password, ERole _role)
        {
            Notifications = new List<Notification>();
            Login = _login;
            Password = _password;
            UserID = Main.Library.NewUserID();
            Role = _role;
            SRole = Role.ToString("G");
            Debug.WriteLine("New user been made!");
        }
        public User()   //for [Serialization()]
        {

        }
        public void printOut()
        {
            Debug.WriteLine($"Login:{Login} Password:{Password} Name:{Name} Surname:{Surname} UserId:{UserID} Role:{Role}");
        }
    }
}