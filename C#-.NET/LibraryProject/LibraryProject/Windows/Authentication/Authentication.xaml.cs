using System.Windows;
using System.Windows.Input;


using System.Diagnostics;
using LibraryProject.Windows.LibraryMainWindow.Views.Admin;

namespace LibraryProject
{
    /// <summary>
    /// Interaction logic for Authentication.xaml
    /// </summary>
    public partial class Authentication : Window
    {
        public Authentication()
        {
            WindowStartupLocation = System.Windows.WindowStartupLocation.CenterScreen;
            Main.SetBooksIcon(this);
            InitializeComponent();
        }
        ~Authentication()
        {
            Debug.WriteLine("Authentication window is destroyed.");
        }

        private void loginButton_Click(object sender, RoutedEventArgs e)
        {
            string login = loginTextBox.Text.ToString();
            string password = passwordBox.Password.ToString();

            if (Main.Library.logConfirm(login, password))
            {
                logResultTextBlock.Text = "Logged successfuly.";
                
                CompleteData completeData = new CompleteData();
                this.Close();
            }
            else
            {
                logResultTextBlock.Text = "Wrong login or password!";
            }


        }

        private void registerButton_Click(object sender, RoutedEventArgs e)
        {
            //this.Hide();
            NewUser newUser_Window = new NewUser(this);
            newUser_Window.Show();
        }

        private void loginTextBox_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.Return)
            {
                loginButton_Click(sender, e as RoutedEventArgs);
            }

        }
    }
}
