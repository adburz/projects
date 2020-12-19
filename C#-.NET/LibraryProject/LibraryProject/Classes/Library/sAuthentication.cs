using System.Diagnostics;

namespace LibraryProject.Classes.Library
{
    public class sAuthentication
    {
        public sAuthentication()
        {
            Debug.WriteLine("Authentication is ON");
        }

        public bool logConfirm(string _login, string _password)
        {
            //loggedUser = users.FirstOrDefault(x => x.Login == _login && x.Password == _password);
            //if (loggedUser!=null)
            //{
            //    loggedUser.printOut();
            //    return true;
            //}
            //else
            //{
                return false;
            //}
            
        }
        public bool ifLoginIsOccupied(string _login)
        {
            //if (users.Exists(x => x.Login == _login))
            //{
            //    return false;
            //}
            //else
            //{
                return true;
            //}
        }
        public void addNewUser(string _login, string _password)
        {
            //try
            //{
            //    users.Add(new User { Login = _login, Password = _password });
            //}
            //catch (Exception e)
            //{
            //    Debug.WriteLine($"Cannot add new user: {e.Message}");
            //}
            //try
            //{

            //    loader.saveUsersData(ref users);
            //}
            //catch (Exception e)
            //{
            //    Debug.WriteLine($"Cannot save users data: {e.Message}");
            //}
        }

    }
}
