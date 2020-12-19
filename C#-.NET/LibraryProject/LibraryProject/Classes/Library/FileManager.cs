using System;
using System.Diagnostics;
using System.Collections.Generic;
//serializacja
using System.IO;
using System.Xml.Serialization;

using LibraryProject.Classes.UserClass;
using LibraryProject.Classes.LibraryEntity;
using LibraryProject.Classes.Rents;

namespace LibraryProject.Classes.Library
{
    public class DataFileManager
    {
        public DataFileManager(ref List<User> users, ref List<Entity> entities, ref List<Author> authors, ref List<Genre> genres, ref Rent rent)
        {
            Debug.WriteLine("DataFileManager CONSTRUCTOR");
            //saveUsersData(ref users);
            loadUsersData(ref users);
            
            //saveEntityData(ref entities);
            loadEntityData(ref entities);

            //saveAuthorData(ref authors);
            loadAuthorData(ref authors);

            //saveGenresData(ref genres);
            loadGenresData(ref genres);

            //saveRentData(ref rent.hires);
            loadRentData(ref rent.hires);

        }
        //- - - - - - - USERS - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        private void loadUsersData(ref List<User> users)
        {
            try
            {
                string path = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, @"DataBase\users.xml");
                XmlSerializer serializer = new XmlSerializer(typeof(List<User>));
                using (FileStream fs = File.OpenRead(path))
                {
                    users = (List<User>)serializer.Deserialize(fs);
                }
            }
            catch (Exception e)
            {
                Debug.WriteLine("Exception in loadUsersData method in Library:");
                Debug.WriteLine(e.Message);
                Main.ExceptionHandler.UsersLoad = false;
            }
        }
        public void saveUsersData(ref List<User> users)
        {
            try
            {
                string path = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, @"DataBase\users.xml");

                //List<Notification> n = new List<Notification> {
                //    new Notification { Message = "wiad1", time = DateTime.Now },
                //    new Notification { Message = "wiad2", time = DateTime.Now } ,
                //    new Notification { Message = "wiad3", time = DateTime.Now } ,
                //};

                //users = new List<User>
                //{
                //    new User{SRole = "Admin",Role=ERole.Admin, Email="ada@gmail.com", ExpiredCount=0, HireCount=0, Login="qwe", Name="Adam", Password="123", Pesel="9806171235", Surname="Trznadel", UserID=1, Notifications = n  },
                //    new User{SRole="Client", Role=ERole.Client, Email="jekot@gmail.com", ExpiredCount=0, HireCount=0, Login="asd", Name="Jeremi", Password="123", Pesel="98061655523", Surname="Kot", UserID=2, Notifications = null },
                //    new User{SRole="Client", Role=ERole.Client, Email="mgoral@gmail.com", ExpiredCount=0, HireCount=0, Login="zxc", Name="Michał", Password="123", Pesel="99061655544", Surname="Góral", UserID=3, Notifications=null }
                //};
                using (Stream fs = new FileStream(path, FileMode.Create, FileAccess.Write, FileShare.None))
                {
                    XmlSerializer serializer = new XmlSerializer(typeof(List<User>));
                    serializer.Serialize(fs, users);
                }
            }
            catch (Exception e)
            {
                Debug.WriteLine("Exception is saveUsersData method in Library:");
                Debug.WriteLine(e.Message);
            }
        }      
        //- - - - - - - LIBRARY ENTITY - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        private void loadEntityData(ref List<Entity> entities)
        {
            try
            {
                string path = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, @"DataBase\entities.xml");

                XmlSerializer serializer = new XmlSerializer(typeof(List<Entity>));
                using (FileStream fs = File.OpenRead(path))
                {
                    entities = (List<Entity>)serializer.Deserialize(fs);
                }
            }
            catch (Exception e)
            {
                Debug.WriteLine("Exception in loadEntityData method in Library:");
                Debug.WriteLine(e.Message);
                Main.ExceptionHandler.EntityLoad = false;
            }
        }
        public void saveEntityData(ref List<Entity> entities)
        {
            try
            {
                string path = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, @"DataBase\entities.xml");

                //entities = new List<Entity>
                //{
                //    new Book{ AuthorID=1, Title="Podróż ludzi Księgi",  GenreID = 1, ID = 1, ISBN = 111223311768, AuthorS="Olga Tokarczuk", GenreS = "Powieść", IsRented=false},
                //    new Book{ AuthorID=1, Title="Szafa",  GenreID = 2, ID = 2, ISBN = 1712277311768, AuthorS="Olga Tokarczuk", GenreS="Opowiadanie/a", IsRented=false},
                //    new Magazine{ ID = 7, Title = "Gazeta Polska", StockNumber = 145, ISBN=1233332226123, IsRented=false},
                //    new Magazine{ ID = 7, Title = "Gazeta Polska", StockNumber = 145, ISBN=1233332226123, IsRented=false},
                //    new Magazine{ ID = 7, Title = "Gazeta Polska", StockNumber = 145, ISBN=1233332226123, IsRented=false},
                //    new Magazine{ ID = 7, Title = "Gazeta Polska", StockNumber = 145, ISBN=1233332226123, IsRented=false},
                //    new Magazine{ ID = 7, Title = "Gazeta Polska", StockNumber = 143, ISBN=1277792226123, IsRented=true},
                //    new Book{ AuthorID=2, Title="Quo Vadis",  GenreID = 3, ID = 3, ISBN = 111777711518, AuthorS="Henryk Sienkiewicz", GenreS="Powieść Historyczna", IsRented=false},
                //    new Book{ AuthorID=2, Title="Quo Vadis",  GenreID = 3, ID = 3, ISBN = 111777711518, AuthorS="Henryk Sienkiewicz", GenreS="Powieść Historyczna", IsRented=false},
                //    new Book{ AuthorID=2, Title="Quo Vadis",  GenreID = 3, ID = 3, ISBN = 111777711518, AuthorS="Henryk Sienkiewicz", GenreS="Powieść Historyczna", IsRented=true},
                //    new Book{ AuthorID=2, Title="Quo Vadis",  GenreID = 3, ID = 3, ISBN = 111777711518, AuthorS="Henryk Sienkiewicz", GenreS="Powieść Historyczna", IsRented=true},

                //    new Magazine{ ID = 4, Title="Programista", StockNumber=1, ISBN= 12312312311234, IsRented=false},
                //    new Magazine{ ID = 6, Title = "Gazeta Polska", StockNumber = 142, ISBN=1233332226660, IsRented=false}                
                //};
                //entities = new List<Entity>
                //{
                //    new Book{ AuthorID=1, Title="Szafa",  GenreID = 1, EntityID = 1, ISBN = 1712277311768, AuthorS="Olga Tokarczuk", GenreS="Opowiadanie/a", IsRented=false},
                //    new Magazine{ EntityID = 2, Title = "First Magazine", StockNumber = 145, ISBN=1233332226123, IsRented=false},
                //    new Magazine{ EntityID = 3, Title = "Second Magazine", StockNumber = 145, ISBN=1233332226123, IsRented=true},
                //    new Book{ AuthorID=2, Title="Quo Vadis",  GenreID = 2, EntityID = 4, ISBN = 111777711518, AuthorS="Henryk Sienkiewicz", GenreS="Powieść Historyczna", IsRented=false},
                //    new Book{ AuthorID=2, Title="Quo Vadis",  GenreID = 2, EntityID = 5, ISBN = 111777711518, AuthorS="Henryk Sienkiewicz", GenreS="Powieść Historyczna", IsRented=true},

                //    new Magazine{ EntityID = 6, Title="CDP:Red", StockNumber=1, ISBN= 12312312311234, IsRented=false},

                //};

                using (Stream fs = new FileStream(path, FileMode.Create, FileAccess.Write, FileShare.None))
                {
                    XmlSerializer serializer = new XmlSerializer(typeof(List<Entity>));

                    serializer.Serialize(fs, entities);
                }
            }
            catch (Exception e)
            {
                Debug.WriteLine("Exception is saveEntityData method in Library:");
                Debug.WriteLine(e.Message);
            }
        }

        //- - - - - - - AUTHOR - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        private void loadAuthorData(ref List<Author> authors)
        {
            try
            {
                string path = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, @"DataBase\authors.xml");

                XmlSerializer serializer = new XmlSerializer(typeof(List<Author>));
                using (FileStream fs = File.OpenRead(path))
                {
                    authors = (List<Author>)serializer.Deserialize(fs);
                }
            }
            catch (Exception e)
            {
                Debug.WriteLine("Exception in loadAuthorData method in Library:");
                Debug.WriteLine(e.Message);
                Main.ExceptionHandler.AuthorLoad = false;
            }
        }
        public void saveAuthorData(ref List<Author> authors)
        {
            try
            {
                string path = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, @"DataBase\authors.xml");

                //authors = new List<Author> {
                //    new Author("Olga Tokarczuk", 1),
                //    new Author("Henryk Sienkiewicz", 2)
                //};
                using (Stream fs = new FileStream(path, FileMode.Create, FileAccess.Write, FileShare.None))
                {
                    XmlSerializer serializer = new XmlSerializer(typeof(List<Author>));
                    serializer.Serialize(fs, authors);
                }
            }
            catch (Exception e)
            {
                Debug.WriteLine("Exception is saveAuthorData method in Library:");
                Debug.WriteLine(e.Message);
            }
        }

        //- - - - - - - GENRES - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
        private void loadGenresData(ref List<Genre> genres)
        {
            try
            {
                string path = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, @"DataBase\genres.xml");

                XmlSerializer serializer = new XmlSerializer(typeof(List<Genre>));
                using (FileStream fs = File.OpenRead(path))
                {
                    genres = (List<Genre>)serializer.Deserialize(fs);
                }
            }
            catch (Exception e)
            {
                Debug.WriteLine("Exception in loadGenresData method in Library:");
                Debug.WriteLine(e.Message);
                Main.ExceptionHandler.GenreLoad = false;
            }
        }
        public void saveGenresData(ref List<Genre> genres)
        {
            try
            {
                //genres = new List<Genre> {
                //            new Genre("Opowiadanie/a", 1), 
                //            new Genre("Powieść Historyczna", 2)  

                //};
                string path = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, @"DataBase\genres.xml");

                using (Stream fs = new FileStream(path, FileMode.Create, FileAccess.Write, FileShare.None))
                {
                    XmlSerializer serializer = new XmlSerializer(typeof(List<Genre>));
                    serializer.Serialize(fs, genres);
                }
            }
            catch (Exception e)
            {
                Debug.WriteLine("Exception is saveGenresData method in Library:");
                Debug.WriteLine(e.Message);
            }
        }
        //- - - - - - - - RENT - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
        private void loadRentData(ref List<Hire> hires)
        {
            try
            {
                string path = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, @"DataBase\hires.xml");

                XmlSerializer serializer = new XmlSerializer(typeof(List<Hire>));
                using (FileStream fs = File.OpenRead(path))
                {
                    hires = (List<Hire>)serializer.Deserialize(fs);
                }
            }
            catch (Exception e)
            {
                Debug.WriteLine("Exception in loadRentData method in Library:");
                Debug.WriteLine(e.Message);
                Main.ExceptionHandler.RentLoad = false;
            }
        }
        public void saveRentData(ref List<Hire> hires)
        {
            try
            {
                string path = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, @"DataBase\hires.xml");

                using (Stream fs = new FileStream(path, FileMode.Create, FileAccess.Write, FileShare.None))
                {
                    XmlSerializer serializer = new XmlSerializer(typeof(List<Hire>));
                    serializer.Serialize(fs, hires);
                }
            }
            catch (Exception e)
            {
                Debug.WriteLine("Exception is saveRentData method in Library:");
                Debug.WriteLine(e.Message);
            }
        }
    }
}
