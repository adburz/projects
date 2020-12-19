using System.Windows;

namespace LibraryProject.Classes.Library
{
    public class ExceptionHandler    //class made to operate on exceptions
    {
        private bool usersLoad = true;
        public bool UsersLoad
        {
            set
            {
                usersLoad = value;
                LoadErrorBox("users");
            }
        }
        private bool entityLoad = true;
        public bool EntityLoad
        {
            set
            {
                entityLoad = value;
                LoadErrorBox("entities");
            }
        }

        private bool authorLoad = true;

        public bool AuthorLoad
        {
            set
            {
                authorLoad = value;
                LoadErrorBox("authors");
            }
        }
        public ExceptionHandler()
        {
        }

        private bool genreLoad = true;
        public bool GenreLoad
        {
            set
            {
                LoadErrorBox("genres");
            }

        }

        private bool rentLoad = true;
        public bool RentLoad
        {
            set
            {
                LoadErrorBox("hires");
            }

        }
        public void LoadErrorBox(string file_name)
        {
            MessageBoxResult errorMessage = MessageBox.Show($"Application can not load {file_name} data. \nClick OK to close it.", "Error_DataBase",
                                                            MessageBoxButton.OK, MessageBoxImage.Question);
            if (errorMessage == MessageBoxResult.OK)
            {
                System.Windows.Application.Current.Shutdown();
            }
        }
    }
}