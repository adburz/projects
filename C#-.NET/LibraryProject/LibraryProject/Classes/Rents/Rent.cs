using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;

namespace LibraryProject.Classes.Rents
{
    [Serializable]
    public class Rent
    {
        public List<Hire> hires;
        public Rent()
        {
            Debug.WriteLine("Rent class made!");
            hires = new List<Hire>();
        }
        public bool DeleteHire(Hire hire)
        {
            if (hires.Remove(hires.FirstOrDefault(x => x.HireID== hire.HireID)))
            {
                return true;
            }
            return false;
        }
        private uint newHireID()
        {
            if(hires.Count == 0)
            {
                return 1;
            }
            else
            {
                return hires[hires.Count - 1].HireID + 1;
            }
        }
        public void AddHire(uint _itemId, uint _userId, string _isbn)
        {
            hires.Add(new Hire(DateTime.Now.AddMinutes(0.5f), newHireID(), _userId, _itemId, _isbn));
        }
        public DateTime GetHireUntilTime(uint _itemId)
        {
            Hire hire = hires.FirstOrDefault(x => x.ItemID == _itemId);
            if(hire is null)
            {
                return DateTime.MaxValue;
            }
            else
            {
                return hire.DateUntil;
            }
        }
    }
}
