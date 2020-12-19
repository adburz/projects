using System.Windows;
using System.Windows.Controls;
using LibraryProject.Classes.UserClass;

namespace LibraryProject.Windows.LibraryMainWindow.Views.Admin.UsersTab
{
    /// <summary>
    /// Interaction logic for AddUser.xaml
    /// </summary>
    public partial class AddUser : Window
    {
        public AddUser(double _left, double _top)
        {
            InitializeComponent();
            Main.SetBooksIcon(this);
            this.Show();
            this.Left = _left;
            this.Top = _top;
        }

        private void Login_TextChanged(object sender, TextChangedEventArgs e)
        {
            if (Login_TextBlock.Text.ToString() == "")
            {
                RegisterButton.IsEnabled = false;
                IsLoginEnable_Label.Content = "";
            }
            else if (Main.Library.ifLoginIsOccupied(Login_TextBlock.Text.ToString()))
            {
                RegisterButton.IsEnabled = true;
                IsLoginEnable_Label.Content = "Login is enable!";
            }
            else
            {
                RegisterButton.IsEnabled = false;
                IsLoginEnable_Label.Content = "Login is not enable.";
            }
        }

        private void RegisterButton_Click(object sender, RoutedEventArgs e)
        {
            string password = null;
            if (Password_PasswordBox.Password.Length > 0)
            {
                password = Password_PasswordBox.Password;
            }
            else
            {
                password = Password_TextBox.Text;
            }

            if ((bool)Client_RadioButton.IsChecked)
            {
                Main.Library.addNewUser(Login_TextBlock.Text.ToString(), password, ERole.Client);

            }
            else
            {
                Main.Library.addNewUser(Login_TextBlock.Text.ToString(), password, ERole.Admin);
            }

            this.Close();
        }

        private void ShowPassword_Changed(object sender, RoutedEventArgs e)
        {
            if ((bool)ShowPassword_CheckBox.IsChecked)
            {
                string password = Password_PasswordBox.Password;
                Password_PasswordBox.Password = "";
                Password_TextBox.Text = password;
                Password_PasswordBox.Visibility = Visibility.Hidden;
                Password_TextBox.Visibility = Visibility.Visible;
            }
            else
            {
                string password = Password_TextBox.Text;
                Password_PasswordBox.Password = password;
                Password_TextBox.Text = "";
                Password_TextBox.Visibility = Visibility.Hidden;
                Password_PasswordBox.Visibility = Visibility.Visible;
            }
        }
    }
}
