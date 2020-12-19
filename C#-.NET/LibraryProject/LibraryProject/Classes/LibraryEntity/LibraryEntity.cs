using System;
using System.Diagnostics;
using System.Xml.Serialization;

namespace LibraryProject.Classes.LibraryEntity
{
    [Serializable()]
    [XmlInclude(typeof(Book))]
    [XmlInclude(typeof(Magazine))]
    public abstract class Entity
    {
        public virtual uint EntityID { get; set; }
        public virtual string Title { get; set; }
        public virtual string ISBN { get; set; }
        public virtual bool IsRented { get; set; }
    }

    public class Book : Entity
    {
        public uint AuthorID { get; set; }
        public uint GenreID { get; set; }
        public string AuthorS { get; set; }
        public string GenreS { get; set; }
        
        public Book(string _title = "none", uint _id = 0, string _isbn = "empty", uint _authorId = 0, uint _genreId = 0, string _author = "", string _genre = "", bool _rented = false)
        {
            EntityID = _id;
            Title = _title;
            ISBN = _isbn;
            AuthorID = _authorId;
            GenreID = _genreId;
            AuthorS = _author;
            GenreS = _genre;
            IsRented = _rented;
            Debug.WriteLine($"Creating new book ID:{EntityID}, Title:{Title}, ISBN:{ISBN}, AuthorID:{AuthorID}, GenreID:{GenreID}, AuthorS:{AuthorS}, GenreS:{GenreS}");
        }
        public Book()   //important for serialization
        {
            EntityID = 0;
            Title = "none";
            ISBN = "empty";
            AuthorID = 0;
            GenreID = 0;
            Debug.WriteLine("Creating EMPTY book.");
        }
    }

    public class Magazine : Entity
    {
        public string StockNumber { get; set; }
        public Magazine(string _title = "None", uint _id = 0, string _isbn = "empty", string _stockNumber="empty")
        {
            EntityID = _id;
            Title = _title;
            ISBN = _isbn;
            StockNumber = _stockNumber;

            Debug.WriteLine($"Creating new magazine ID:{EntityID}, Title:{Title}, ISBN:{ISBN}");
        }
        public Magazine()
        {
            EntityID = 0;
            Title = "None";
            ISBN = "empty";
            Debug.WriteLine("Creating EMPTY book.");
        }   //important for serialization
    }
}
