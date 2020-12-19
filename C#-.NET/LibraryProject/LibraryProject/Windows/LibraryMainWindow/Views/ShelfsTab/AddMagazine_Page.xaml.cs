using System;
using System.Text.RegularExpressions;
using System.Windows;
using System.Windows.Controls;

namespace LibraryProject.Windows.LibraryMainWindow.Views.Admin.ShelfsTab
{
    /// <summary>
    /// Interaction logic for AddMagazine_Page.xaml
    /// </summary>
    public partial class AddMagazine_Page : Page
    {
        public AddMagazine_Page()
        {
            InitializeComponent();
        }
        private bool IsValidGtin(string code)
        {
            if (code != (new Regex("[^0-9]")).Replace(code, ""))
            {
                // is not numeric
                return false;
            }
            // pad with zeros to lengthen to 14 digits
            switch (code.Length)
            {
                case 8:
                    code = "000000" + code; 
                    break;
                case 12:
                    code = "00" + code;
                    break;
                case 13:
                    code = "0" + code;
                    break;
                case 14:
                    break;
                default:
                    // wrong number of digits
                    return false;
            }
            // calculate check digit
            int[] a = new int[13];
            a[0] = int.Parse(code[0].ToString()) * 3;
            a[1] = int.Parse(code[1].ToString());
            a[2] = int.Parse(code[2].ToString()) * 3;
            a[3] = int.Parse(code[3].ToString());
            a[4] = int.Parse(code[4].ToString()) * 3;
            a[5] = int.Parse(code[5].ToString());
            a[6] = int.Parse(code[6].ToString()) * 3;
            a[7] = int.Parse(code[7].ToString());
            a[8] = int.Parse(code[8].ToString()) * 3;
            a[9] = int.Parse(code[9].ToString());
            a[10] = int.Parse(code[10].ToString()) * 3;
            a[11] = int.Parse(code[11].ToString());
            a[12] = int.Parse(code[12].ToString()) * 3;
            int sum = a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6] + a[7] + a[8] + a[9] + a[10] + a[11] + a[12];
            int check = (10 - (sum % 10)) % 10;
            // evaluate check digit
            int last = int.Parse(code[13].ToString());
            return check == last;
        }

        private void ISSN_TextBox_Changed(object sender, TextChangedEventArgs e)
        {
            if(IsValidGtin(ISSN_TextBox.Text))
            {
                ISSN_Aviable_Label.Content = "ISSN is aviable.";
                Value_Changed(sender, e);
            }
            else
            {
                ISSN_Aviable_Label.Content = "ISSN is not aviable";
                AddMagazine_Button.IsEnabled = false;
            }
        }

        private void Value_Changed(object sender, TextChangedEventArgs e)
        {
            if (!String.IsNullOrEmpty(Title_TextBox.Text)
                && !String.IsNullOrEmpty(ISSN_TextBox.Text)
                && !String.IsNullOrEmpty(StockNumber_TextBox.Text))
            {
                AddMagazine_Button.IsEnabled = true;
            }
            else
            {
                AddMagazine_Button.IsEnabled = false;
            }
        }

        private void AddMagazine_Click(object sender, RoutedEventArgs e)
        {
            if (Main.Library.IfISBNExists(ISSN_TextBox.Text))
            {
                ifMagazineExists.Text = "Magazine with this ISSN already exists.";
            }
            else
            {
                ifMagazineExists.Text = "Magazine added.";
                Main.Library.AddMagazine(Title_TextBox.Text, ISSN_TextBox.Text, StockNumber_TextBox.Text);
            }
        }
    }
}
