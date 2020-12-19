using LibraryProject.Classes.LibraryEntity;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows;
using System.Windows.Controls;

namespace LibraryProject.Windows.LibraryMainWindow.Views.Admin.ShelfsTab
{
    /// <summary>
    /// Interaction logic for AddBook_Page.xaml
    /// </summary>
    public partial class AddBook_Page : Page
    {
        public AddBook_Page()
        {
            InitializeComponent();
            setAuthorComboBox();
            setGenreComboBox();
        }
        private void setAuthorComboBox()
        {
            List<Author> authors = new List<Author>(Main.Library.GetAuthors());
            authors.Insert(0, new Author("Select Author", 0));
            Author_ComboBox.ItemsSource = authors;
            Author_ComboBox.DisplayMemberPath = "Name";
            Author_ComboBox.SelectedValuePath = "AuthorID";
            Author_ComboBox.SelectedIndex = 0;
            authors = null;
        }
        private void setGenreComboBox()
        {
            List<Genre> genres = new List<Genre>(Main.Library.GetGenres());
            genres.Insert(0, new Genre("Select Genre", 0));
            Genre_ComboBox.ItemsSource = null;
            Genre_ComboBox.ItemsSource = genres;
            Genre_ComboBox.DisplayMemberPath = "Name";
            Genre_ComboBox.SelectedValuePath = "GenreID";
            Genre_ComboBox.SelectedIndex = 0;
            genres = null;
        }
        private bool isValidISBN(string isbn13)
        {
            bool result = false;
            if (!string.IsNullOrEmpty(isbn13) && isbn13.Length == 13)
            {
                for (int i = 0; i < isbn13.Length; i++)
                {
                    if (!Char.IsNumber(isbn13[i]))
                    {
                        return result;
                    }
                }
                long j;
                if (isbn13.Contains('-')) isbn13 = isbn13.Replace("-", "");
                // Check if it contains any non numeric chars, if yes, return false
                if (!Int64.TryParse(isbn13, out j))
                    result = false;
                int sum = 0;

                // Comment Source: Wikipedia

                // The calculation of an ISBN-13 check digit begins with the first

                // 12 digits of the thirteen-digit ISBN (thus excluding the check digit itself).

                // Each digit, from left to right, is alternately multiplied by 1 or 3,

                // then those products are summed modulo 10 to give a value ranging from 0 to 9.

                // Subtracted from 10, that leaves a result from 1 to 10. A zero (0) replaces a

                // ten (10), so, in all cases, a single check digit results.

                for (int i = 0; i < 12; i++)
                {
                    sum += Int32.Parse(isbn13[i].ToString()) * (i % 2 == 1 ? 3 : 1);
                }
                int remainder = sum % 10;
                int checkDigit = 10 - remainder;
                if (checkDigit == 10) checkDigit = 0;
                result = (checkDigit == int.Parse(isbn13[12].ToString()));
            }
            return result;
        }
        private void Value_Changed(object sender, TextChangedEventArgs e)
        {
            if (!String.IsNullOrEmpty(Title_TextBox.Text)
                && !String.IsNullOrEmpty(ISBN_TextBox.Text)
                && !String.IsNullOrEmpty(Author_TextBox.Text)
                && !String.IsNullOrEmpty(Genre_TextBox.Text))
            {
                AddBook_Button.IsEnabled = true;
            }
            else
            {
                AddBook_Button.IsEnabled = false;
            }
        }
        private void AuthorComboBox_Changed(object sender, SelectionChangedEventArgs e)
        {
            if (Author_ComboBox.SelectedIndex == 0 || Author_ComboBox.SelectedIndex < 0 /*index = -1 while reloading ItemsSource*/)
            {
                return;
            }
            else
            {
                Author ComboItem = (Author)Author_ComboBox.SelectedItem;
                Author_TextBox.Text = ComboItem.Name;
                ComboItem = null;
            }
        }
        private void GenreComboBox_Changed(object sender, SelectionChangedEventArgs e)
        {
            if (Genre_ComboBox.SelectedIndex == 0 || Genre_ComboBox.SelectedIndex<0 /*index = -1 while reloading ItemsSource*/)
            {
                return;
            }
            else
            {
                Genre ComboItem = (Genre)Genre_ComboBox.SelectedItem;
                Genre_TextBox.Text = ComboItem.Name;
                ComboItem = null;
            }
        }
        private void ISBN_TextBox_Changed(object sender, TextChangedEventArgs e)
        {
            if (isValidISBN(ISBN_TextBox.Text))
            {
                Value_Changed(sender, e);
                ISBN_Aviable_Label.Content = "ISBN is valid";

            }
            else
            {
                AddBook_Button.IsEnabled = false;
                ISBN_Aviable_Label.Content = "Invalid ISBN";
            }
        }

        private void AddBook_Click(object sender, RoutedEventArgs e)
        {
            if (Main.Library.IfISBNExists(ISBN_TextBox.Text))
            {
                ifBookExists.Text = "Book with this ISBN already exists.";
            }
            else
            {
                ifBookExists.Text = "Book added.";
                Main.Library.AddBook(Title_TextBox.Text, ISBN_TextBox.Text, Author_TextBox.Text, Genre_TextBox.Text);
                setAuthorComboBox();
                setGenreComboBox();
            }
        }
    }
}
