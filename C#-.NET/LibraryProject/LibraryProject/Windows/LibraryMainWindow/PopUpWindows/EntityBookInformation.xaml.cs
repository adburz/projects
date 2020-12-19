using System.Windows;
using System.Diagnostics;

namespace LibraryProject.Windows.LibraryMainWindow.PopUpWindows
{
    /// <summary>
    /// Interaction logic for EntityBookInformation.xaml
    /// </summary>
    public partial class EntityBookInformation : Window
    {
        public EntityBookInformation()
        {
            InitializeComponent();
            Show();
            Debug.WriteLine("Entity Book Information");
        }
    }
}
