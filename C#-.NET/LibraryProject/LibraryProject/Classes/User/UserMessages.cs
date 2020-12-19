using System;

namespace LibraryProject.Classes.UserClass
{
    [Serializable]
    public class Notification
    {
        public string Message { get; set; }
        public DateTime time { get; set; }

        public Notification(string _message)
        {
            time = DateTime.Now;
            Message = _message;
        }
        public Notification()
        {

        }
    }
}
