using System;

namespace LibraryProject.Classes.LibraryEntity
{
    [Serializable()]
    public class Author
    {
        public string Name { get; set; }
        public uint AuthorID { get; set; }
        public Author()
        {

        }
        public Author(string _name ="nEmpty", uint _id = 999)
        {
            Name = _name;
            AuthorID = _id;
        }
    }
}
