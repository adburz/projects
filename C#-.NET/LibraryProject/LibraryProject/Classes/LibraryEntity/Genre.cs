

namespace LibraryProject.Classes.LibraryEntity
{
    public class Genre
    {
        public uint GenreID { get; set; }
        public string Name { get; set; }
        public Genre(string _name = "None", uint _id=0)
        {
            GenreID = _id;
            Name = _name;
        }
        public Genre()
        {

        }
    }
}
