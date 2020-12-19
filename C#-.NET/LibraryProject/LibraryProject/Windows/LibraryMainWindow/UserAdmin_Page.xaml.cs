using System.Windows;
using System.Windows.Controls;

using LibraryProject.Windows.LibraryMainWindow.Views.Admin;
namespace LibraryProject.Windows.LibraryMainWindow
{
    /// <summary>
    /// Interaction logic for UserAdmin_Page.xaml
    /// </summary>
    public enum ETab
    {
        Shelfs, Users, Borrowed
    }
    public partial class UserAdmin_Page : Page
    {
        private ETab tabType = ETab.Shelfs;
        
        public UserAdmin_Page()
        {
            InitializeComponent();
            DataContext = new Shelfs_MainWindow();
        }
        private void booksView_Clicked(object sender, RoutedEventArgs e)
        {
            if (tabType != ETab.Shelfs)
            {
                DataContext = new Shelfs_MainWindow();
                tabType = ETab.Shelfs;
            }
            else
            {
                return;
            }
        }
        private void usersView_Clicked(object sender, RoutedEventArgs e)
        {
            if (tabType != ETab.Users)
            {
                DataContext = new Users_MainWindow();
                tabType = ETab.Users;
            }
            else
            {
                return;
            }
        }

        private void borrowersView_Clicked(object sender, RoutedEventArgs e)
        {
            if(tabType != ETab.Borrowed)
            {
                DataContext = new Borrow_MainWindow();
                tabType = ETab.Borrowed;
            }    
            else
            {
                return;
            }
        }

    }
}
