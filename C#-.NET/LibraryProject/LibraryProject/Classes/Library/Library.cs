using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;

using LibraryProject.Classes.UserClass;
using LibraryProject.Classes.LibraryEntity;
using LibraryProject.Classes.Rents;
using System.Windows.Threading;

namespace LibraryProject.Classes.Library
{

    public class Library
    {
        private static DispatcherTimer _dataUpdateTimer = null;
        private static DispatcherTimer _penaltyUpdateTimer = null;
        protected static User loggedUser { get; set; }
        public static Rent rent;
        public static List<User> users;
        protected List<Entity> libraryEntities;
        protected List<Author> authors;
        protected List<Genre> genres;

        protected static DataFileManager loader;
        public Library()
        {
            Debug.WriteLine("Library CONSTRUCTOR");
            users = new List<User>();
            libraryEntities = new List<Entity>();
            authors = new List<Author>();
            genres = new List<Genre>();
            rent = new Rent();
            loader = new DataFileManager(ref users, ref libraryEntities, ref authors, ref genres, ref rent);
            loggedUser = new User();
            SetupDataUpdateTimer();
            //startTimerMethod();
        }
        ~Library()
        {
            Debug.WriteLine("Closing Library");
            loader.saveUsersData(ref users);
            loader.saveEntityData(ref libraryEntities);
            loader.saveAuthorData(ref authors);
            loader.saveGenresData(ref genres);
            loader.saveRentData(ref rent.hires);
        }

        //_____________ TIMER METHOD ___________

        private void SetupDataUpdateTimer()
        {
            _dataUpdateTimer = new DispatcherTimer();
            _penaltyUpdateTimer = new DispatcherTimer();

            _dataUpdateTimer.Tick += OnDataUpdateEvent;
            _dataUpdateTimer.Interval = TimeSpan.FromMilliseconds(10000);
            _penaltyUpdateTimer.Tick += OnPenaltyUpdateEvent;
            _penaltyUpdateTimer.Interval = TimeSpan.FromHours(1);

            _penaltyUpdateTimer.Start();
            _dataUpdateTimer.Start();
        }
        private void OnDataUpdateEvent(object sender, EventArgs e)
        {
            Debug.WriteLine("tajmer_date");
            DateTime now = DateTime.Now;
            foreach (Hire h in rent.hires)
            {
                if (h.DateUntil < now)
                {
                    if (h.isExpired == false)
                    {
                        users.Find(x => x.UserID == h.UserID).ExpiredCount++;
                        h.isExpired = true;
                    }
                }
            }
        }
        private void OnPenaltyUpdateEvent(object sender, EventArgs e)
        {
            Debug.WriteLine("tajmer_penalty");
            DateTime now = DateTime.Now;
            foreach (Hire h in rent.hires)
            {
                if (now > h.DateUntil)
                {
                    h.Penalty = (int)((now - h.DateUntil).TotalDays);
                }
            }
        }

        //============= NOTIFICATIONS ==========
        public void ClearMessages()
        {
            users.Find(x => x == loggedUser).Notifications.Clear();
        }
        public void AddNotification(string message, uint _userID)
        {
            try
            {
                int index = getUserIndex(_userID);
                users[index].Notifications.Add(new Notification(message));
                loader.saveUsersData(ref users);
            }
            catch (Exception e)
            {
                Debug.WriteLine("Error in AddNotification method");
                Debug.WriteLine(e.Message);

            }
        }
        //_ _ _ _ _ _ _ GET METHODS _ _ _ _ _ _ _ 
        public void Closing()
        {
            loader.saveEntityData(ref libraryEntities);
            loader.saveUsersData(ref users);
            loader.saveAuthorData(ref authors);
            loader.saveGenresData(ref genres);
            loader.saveRentData(ref rent.hires);
        }
        //********************** HIRE METHODS *******************
        public void DeleteHire(Hire hire)
        {
            if (rent.DeleteHire(hire))
            {
                User u = users.FirstOrDefault(x => x.UserID == hire.UserID);
                u.HireCount--;
                if (hire.isExpired)
                {
                    u.ExpiredCount--;
                }
                libraryEntities.Find(x => x.EntityID == hire.ItemID).IsRented = false;
                loader.saveRentData(ref rent.hires);
                loader.saveEntityData(ref libraryEntities);
            }
        }
        public void HireItem(Entity item)
        {
            rent.AddHire(item.EntityID, loggedUser.UserID, item.ISBN);
            libraryEntities.Find(x => x.EntityID == item.EntityID).IsRented = true;
            users.Find(x => x.UserID == loggedUser.UserID).HireCount++;
        }
        public DateTime GetUntilTime(uint _itemId)
        {
            return rent.GetHireUntilTime(_itemId);
        }
        public List<Hire> GetHires()
        {
            return rent.hires;
        }
        //###################### ENTITY METHODS #################
        public uint NewEntityID()
        {
            if (libraryEntities is null)
            {
                return 1;
            }
            else
            {
                return libraryEntities[libraryEntities.Count - 1].EntityID + 1;
            }
        }
        public string GetTitle(uint _itemID)
        {
            string title = libraryEntities.FirstOrDefault(x => x.EntityID == _itemID).Title;
            if (String.IsNullOrEmpty(title))
            {
                return "empty";
            }
            return title;
        }
        public bool IfISBNExists(string _isbn)
        {
            if (libraryEntities.FirstOrDefault(x => x.ISBN == _isbn) is null)
            {
                return false;
            }
            return true;
        }
        public ref List<Entity> GetEntities()
        {
            return ref libraryEntities;
        }
        public List<Genre> GetGenres()
        {
            return genres;
        }
        public uint GetGenreID(string _name)
        {
            return genres.Find(x => x.Name == _name).GenreID;
        }
        public List<Author> GetAuthors()
        {
            return authors;
        }
        private bool findAuthor(string _name)
        {
            if (authors.FirstOrDefault(x => x.Name == _name) is null)
            {
                return false;
            }
            return true;
        }
        private uint getAuthorID(string _name)
        {
            if (findAuthor(_name))
            {
                return authors.Find(x => x.Name == _name).AuthorID;
            }
            else
            {
                uint id = NewAuthorID();
                authors.Add(new Author(_name, id));
                loader.saveAuthorData(ref authors);
                return id;
            }
        }
        private uint NewAuthorID()
        {
            if (authors is null)
            {
                return 1;
            }
            else
            {
                return authors[authors.Count - 1].AuthorID + 1;
            }
        }
        private bool findGenre(string _name)
        {
            if (genres.FirstOrDefault(x => x.Name == _name) is null)
            {
                return false;
            }
            return true;
        }
        private uint getGenresID(string _name)
        {
            if (findGenre(_name))
            {
                return genres.Find(x => x.Name == _name).GenreID;
            }
            else
            {
                uint id = NewGenreID();
                genres.Add(new Genre(_name, id));
                loader.saveGenresData(ref genres);
                return id;
            }
        }
        public void AddBook(string _title, string _isbn, string _author, string _genre)
        {
            uint authorID = getAuthorID(_author);
            uint genreID = getGenresID(_genre);
            libraryEntities.Add(new Book(_title, NewEntityID(), _isbn, authorID, genreID, _author, _genre));
            loader.saveEntityData(ref libraryEntities);
        }
        public void AddMagazine(string _title, string _isbn, string _stockNumber)
        {
            libraryEntities.Add(new Magazine(_title, NewEntityID(), _isbn, _stockNumber));
            loader.saveEntityData(ref libraryEntities);
        }
        public uint NewGenreID()
        {
            if (genres is null)
            {
                return 1;
            }
            else
            {
                return genres[genres.Count - 1].GenreID + 1;
            }
        }
        public void DeleteEntity(uint _id)
        {
            if (libraryEntities.Remove(libraryEntities.FirstOrDefault(x => x.EntityID == _id)))
            {
                loader.saveEntityData(ref libraryEntities);
            }
        }

        //$$$$$$$$$$$$$$$$$$$$$$ USER METHODS $$$$$$$$$$$$$$$$$$$
        public ref List<User> GetUsers()
        {
            return ref users;
        }
        public uint NewUserID()
        {
            if (users is null)
            {
                return 1;
            }
            else
            {
                return users[users.Count - 1].UserID + 1;
            }
        }
        public User GetLoggedUser()
        {
            return loggedUser;
        }
        public bool logConfirm(string _login, string _password)
        {
            loggedUser = users.FirstOrDefault(x => x.Login == _login && x.Password == _password);
            if (loggedUser != null)
            {
                loggedUser.printOut();
                return true;
            }
            else
            {
                return false;
            }

        }
        public bool ifLoginIsOccupied(string _login)
        {
            if (users.Exists(x => x.Login == _login))
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        private int getUserIndex(uint _userID)
        {
            int index = 0;
            while (users[index].UserID != _userID)
            {
                index++;
            }
            return index;
        }
        //__________ USER LIST METHODS _________
        public void DeleteUser(uint _id)
        {
            rent.hires.RemoveAll(x => x.UserID == _id);
            users.Remove(users.FirstOrDefault(x => x.UserID == _id));
            loader.saveUsersData(ref users);
        }
        public void addNewUser(string _login, string _password, ERole _role)
        {
            try
            {
                users.Add(new User(_login, _password, _role));
            }
            catch (Exception e)
            {
                Debug.WriteLine($"Cannot add new user: {e.Message}");
            }
            try
            {
                loader.saveUsersData(ref users);
            }
            catch (Exception e)
            {
                Debug.WriteLine($"Cannot save users data: {e.Message}");
            }
        }

        //________________ COMPLETE USER DATA WINDOW METHODS _______________s
        public void UpdateUserData(string _password, string _name, string _surname, string _pesel, string _email, string _phoneNumber)
        {
            int i = getUserIndex(loggedUser.UserID);
            if (_password != "")
            {
                users[i].Password = _password;
            }
            if (_name != "")
            {
                users[i].Name = _name;
            }
            if (_surname != "")
            {
                users[i].Surname = _surname;
            }
            if (_pesel != "")
            {
                users[i].Pesel = _pesel;
            }
            if (_email != "")
            {
                users[i].Email = _email;
            }
            if (_phoneNumber != "")
            {
                users[i].PhoneNumber = _phoneNumber;
            }
            loader.saveUsersData(ref users);
            loggedUser = users[i];
        }
    }
}
