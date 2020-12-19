using System.Windows;
using System.Windows.Controls;
using LibraryProject.Classes.UserClass;

namespace LibraryProject
{
    /// <summary>
    /// Interaction logic for Window1.xaml
    /// </summary>
    public partial class NewUser : Window
    {
        Authentication prevWindow;
        public NewUser(Authentication _authentication)
        {
            prevWindow = _authentication;
            prevWindow.Hide();
            this.Left = _authentication.Left;
            this.Top = _authentication.Top;
            InitializeComponent();
            Main.SetBooksIcon(this);
        }
        private void login_TextChanged(object sender, TextChangedEventArgs e)
        {
            if (loginTextBox.Text.ToString() == "")
            {
                registerButton.IsEnabled = false;
                ifLoginIsOpen.Text = "";
            }
            else if (Main.Library.ifLoginIsOccupied(loginTextBox.Text.ToString()))
            {
                //mozna nacisnac register
                registerButton.IsEnabled = true;
                ifLoginIsOpen.Text = "Login is allowed.";
            }
            else
            {
                //nie mozna nacisnac register
                registerButton.IsEnabled = false;
                ifLoginIsOpen.Text = "Login was already taken.";
            }
        }

        private void NewUserWindow_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            prevWindow.Show();
        }

        private void registerButton_Click(object sender, RoutedEventArgs e)
        {
            if (Password_PasswordBox.Password.Length > 0)
            {
                Main.Library.addNewUser(loginTextBox.Text.ToString(), Password_PasswordBox.Password.ToString(), ERole.Client);
            }
            else
            {
                Main.Library.addNewUser(loginTextBox.Text.ToString(), Password_TextBox.Text.ToString(), ERole.Client);
            }
            prevWindow.Show();
            this.Close();
        }

        private void checkBox_Checked(object sender, RoutedEventArgs e)
        {
            if ((bool)showPassCheckBox.IsChecked)
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
