using LibraryProject.Classes.UserClass;
using System.Windows;

namespace LibraryProject.Windows.LibraryMainWindow.Views.Admin
{
    /// <summary>
    /// Interaction logic for CompleteData.xaml
    /// </summary>
    public partial class CompleteData : Window
    {
        public CompleteData()
        {
            Main.SetBooksIcon(this);
            this.WindowStartupLocation = WindowStartupLocation.CenterScreen;
            InitializeComponent();
            IsQuitIsEnable();
            SetData();
            this.Show();
        }

        private void SetData()
        {
            User u = Main.Library.GetLoggedUser();
            if (u.Password != "")
            {
                Password_Box.Password = u.Password.ToString();
            }
            if (u.Name != "empty")
            {
                Name_TextBox.Text = u.Name.ToString();
            }
            if (u.Surname != "empty")
            {
                Surname_TextBox.Text = u.Surname.ToString();
            }
            if (u.Pesel != "empty")
            {
                Pesel_TextBox.Text = u.Pesel.ToString();
            }
            if (u.Email != "empty")
            {
                Email_TextBox.Text = u.Email.ToString();
            }
            if (u.PhoneNumber != "empty")
            {
                PhoneNumber_TextBox.Text = u.PhoneNumber.ToString();
            }
            u = null;
        }

        private void IsQuitIsEnable()
        {
            User u = Main.Library.GetLoggedUser();
            if (u.Name is "empty" || u.Surname is "empty" || u.Pesel is "empty")
            {
                Quit_Button.IsEnabled = false;
            }
            else
            {
                Quit_Button.IsEnabled = true;
            }
            u = null;
        }
        private int CalculateControlSum(string input, int[] weights, int offset = 0)
        {
            //code from site http://kozub.net.pl/2012/03/22/c-extension-methods-uzupelnienie/
            int controlSum = 0;
            for (int i = 0; i < input.Length - 1; i++)
            {
                controlSum += weights[i + offset] * int.Parse(input[i].ToString());
            }
            return controlSum;
        }
        private bool IsPeselValid()
        {
            //code from site http://kozub.net.pl/2012/03/22/c-extension-methods-uzupelnienie/
            int[] weights = { 1, 3, 7, 9, 1, 3, 7, 9, 1, 3 };
            bool result = false;
            if (Pesel_TextBox.Text.Length == 11)
            {
                int controlSum = CalculateControlSum(Pesel_TextBox.Text, weights);
                int controlNum = controlSum % 10;
                controlNum = 10 - controlNum;
                if (controlNum == 10)
                {
                    controlNum = 0;
                }
                int lastDigit = int.Parse(Pesel_TextBox.Text[Pesel_TextBox.Text.Length - 1].ToString());
                result = controlNum == lastDigit;
            }
            return result;
        }
        private bool canBeUpdated()
        {
            if (Name_TextBox.Text != "" || Surname_TextBox.Text != "" || Pesel_TextBox.Text != "")
            {
                if (IsPeselValid())
                {
                    Pesel_Label.Content = "PESEL*:";
                    return true;
                }
                else
                {
                    Pesel_Label.Content = "PESEL*:    (invalid PESEL)";
                }
            }
                return false;
        }
        private void UpdateData_Click(object sender, RoutedEventArgs e)
        {
            if (canBeUpdated())
            {
                Main.Library.UpdateUserData(Password_Box.Password, Name_TextBox.Text,
                                            Surname_TextBox.Text, Pesel_TextBox.Text,
                                            Email_TextBox.Text, PhoneNumber_TextBox.Text);
                Update_Label.Text = "Update complete!";
            }
            else
            {
                Update_Label.Text = "";
            }
            IsQuitIsEnable();
        }

        private void Quit_Clicked(object sender, RoutedEventArgs e)
        {
            Library_MainWindow mainWindow = new Library_MainWindow();
            this.Close();
        }
    }
}
