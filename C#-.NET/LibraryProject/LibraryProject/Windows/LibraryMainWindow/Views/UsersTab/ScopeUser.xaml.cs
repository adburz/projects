using LibraryProject.Classes.UserClass;
using System.Linq;
using System.Windows;

namespace LibraryProject.Windows.LibraryMainWindow.Views.Admin.UsersTab
{
    /// <summary>
    /// Interaction logic for ScopeUser.xaml
    /// </summary>
    public partial class ScopeUser : Window
    {
        private uint userID { get; set; }
        public ScopeUser( User _user, double _left, double _top)
        {
            userID = _user.UserID;
            InitializeComponent();
            Login_TextBox.Text = _user.Login;
            Name_TextBox.Text = _user.Name;
            Surname_TextBox.Text = _user.Surname;
            Pesel_TextBox.Text = _user.Pesel;
            Email_TextBox.Text = _user.Email;
            PhoneNumber_TextBox.Text = _user.PhoneNumber;
            HireCount_TextBox.Content = _user.HireCount.ToString();
            ExpiredCount_TextBox.Content = _user.ExpiredCount.ToString();
            Main.SetBooksIcon(this);
            this.Show();
            this.Left = _left;
            this.Top = _top;
          
        }

        private void Quit_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }

        private void SendNotification_Click(object sender, RoutedEventArgs e)
        {
            if(Application.Current.Windows.OfType<ScopeUser_SendNotification>().Any())
            {
                return;
            }
            else { 
            ScopeUser_SendNotification notificationWindow = new ScopeUser_SendNotification(userID, Application.Current.MainWindow.Left + 60, Application.Current.MainWindow.Top+ 60);
            }
        }
    }
}
