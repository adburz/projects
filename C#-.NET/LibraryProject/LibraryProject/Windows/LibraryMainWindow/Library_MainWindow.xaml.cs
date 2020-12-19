using LibraryProject.Classes.UserClass;
using LibraryProject.Windows.LibraryMainWindow.PopUpWindows;
using System.Windows;

namespace LibraryProject.Windows.LibraryMainWindow
{
    /// <summary>
    /// Interaction logic for Library_MainWindow.xaml
    /// </summary>
    public partial class Library_MainWindow : Window
    {
        public Library_MainWindow()
        {
            Main.SetBooksIcon(this);
            InitializeComponent();
            this.Show();
            Main.SetBooksIcon(this);
            if (Main.Library.GetLoggedUser().Role == ERole.Admin)
            {
                LibraryContent_MainWindow.Content = new UserAdmin_Page();
            }
            else
            {
                LibraryContent_MainWindow.Content = new UserClient_Page();
            }
            NotificationWindow notificationWindow = new NotificationWindow();
        }
        private void Library_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            Main.Library.Closing();
        }
    }
}
