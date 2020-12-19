using System;

namespace LibraryProject.Classes.Rents
{
    [Serializable]
    public class Hire
    {
        public DateTime DateFrom { get; set; }
        public DateTime DateUntil { get; set; }
        public string ISBN { get; set; }
        public uint HireID { get; set; }
        public uint ItemID { get; set; }
        public uint UserID { get; set; }
        public bool isExpired { get; set; }
        public int Penalty { get; set; }

        public Hire(DateTime _dateUntil, uint _hireId, uint _userId, uint _itemId, string _isbn)
        {
            DateFrom = DateTime.Now;
            DateUntil = _dateUntil;
            ISBN = _isbn;
            HireID = _hireId;
            ItemID = _itemId;
            UserID = _userId;
            isExpired = false;
            Penalty = 0;
        }

        Hire()
        {
            HireID = 0;
            ItemID = 0;
            isExpired = false;
            Penalty = 0;
        }
    }
}
