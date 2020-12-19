using System.Windows;
using System.Windows.Controls;

using LibraryProject.Windows.LibraryMainWindow.Views.Admin;

namespace LibraryProject.Windows.LibraryMainWindow
{
    /// <summary>
    /// Interaction logic for UserClient_Page.xaml
    /// </summary>
    
    public partial class UserClient_Page : Page
    {
        ETab tabType ;
        public UserClient_Page()
        {
            InitializeComponent();
            tabType = ETab.Shelfs;
            Content_UserClient_Page.Content = new Shelfs_MainWindow();
        }

        private void borrowed_Click(object sender, RoutedEventArgs e)
        {
            if(tabType == ETab.Borrowed)
            {
                return;
            }
            else
            {
                tabType = ETab.Borrowed;
                Content_UserClient_Page.Content = new Borrow_MainWindow();
            }
        }

        private void Shelfs_Click(object sender, RoutedEventArgs e)
        {
            if (tabType == ETab.Shelfs)
            {
                return;
            }
            else
            {
                tabType = ETab.Shelfs;
                Content_UserClient_Page.Content = new Shelfs_MainWindow();
            }
        }
    }
}
