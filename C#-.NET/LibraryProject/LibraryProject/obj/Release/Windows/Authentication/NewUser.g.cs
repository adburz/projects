﻿#pragma checksum "..\..\..\..\Windows\Authentication\NewUser.xaml" "{8829d00f-11b8-4213-878b-770e8597ac16}" "1084A52967F5DF0395F5C4A3EFD5E2C06EAA402CDECFCCF901BBE24F442A7A50"
//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.42000
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

using LibraryProject;
using System;
using System.Diagnostics;
using System.Windows;
using System.Windows.Automation;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Effects;
using System.Windows.Media.Imaging;
using System.Windows.Media.Media3D;
using System.Windows.Media.TextFormatting;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Shell;


namespace LibraryProject {
    
    
    /// <summary>
    /// NewUser
    /// </summary>
    public partial class NewUser : System.Windows.Window, System.Windows.Markup.IComponentConnector {
        
        
        #line 28 "..\..\..\..\Windows\Authentication\NewUser.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.TextBox loginTextBox;
        
        #line default
        #line hidden
        
        
        #line 32 "..\..\..\..\Windows\Authentication\NewUser.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.TextBlock ifLoginIsOpen;
        
        #line default
        #line hidden
        
        
        #line 38 "..\..\..\..\Windows\Authentication\NewUser.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.PasswordBox passwordBox;
        
        #line default
        #line hidden
        
        
        #line 41 "..\..\..\..\Windows\Authentication\NewUser.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.CheckBox showPassCheckBox;
        
        #line default
        #line hidden
        
        
        #line 44 "..\..\..\..\Windows\Authentication\NewUser.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Button registerButton;
        
        #line default
        #line hidden
        
        private bool _contentLoaded;
        
        /// <summary>
        /// InitializeComponent
        /// </summary>
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.CodeDom.Compiler.GeneratedCodeAttribute("PresentationBuildTasks", "4.0.0.0")]
        public void InitializeComponent() {
            if (_contentLoaded) {
                return;
            }
            _contentLoaded = true;
            System.Uri resourceLocater = new System.Uri("/LibraryProject;component/windows/authentication/newuser.xaml", System.UriKind.Relative);
            
            #line 1 "..\..\..\..\Windows\Authentication\NewUser.xaml"
            System.Windows.Application.LoadComponent(this, resourceLocater);
            
            #line default
            #line hidden
        }
        
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.CodeDom.Compiler.GeneratedCodeAttribute("PresentationBuildTasks", "4.0.0.0")]
        [System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Never)]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Design", "CA1033:InterfaceMethodsShouldBeCallableByChildTypes")]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Maintainability", "CA1502:AvoidExcessiveComplexity")]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1800:DoNotCastUnnecessarily")]
        void System.Windows.Markup.IComponentConnector.Connect(int connectionId, object target) {
            switch (connectionId)
            {
            case 1:
            
            #line 9 "..\..\..\..\Windows\Authentication\NewUser.xaml"
            ((LibraryProject.NewUser)(target)).Closing += new System.ComponentModel.CancelEventHandler(this.NewUserWindow_Closing);
            
            #line default
            #line hidden
            return;
            case 2:
            this.loginTextBox = ((System.Windows.Controls.TextBox)(target));
            
            #line 28 "..\..\..\..\Windows\Authentication\NewUser.xaml"
            this.loginTextBox.TextChanged += new System.Windows.Controls.TextChangedEventHandler(this.login_TextChanged);
            
            #line default
            #line hidden
            return;
            case 3:
            this.ifLoginIsOpen = ((System.Windows.Controls.TextBlock)(target));
            return;
            case 4:
            this.passwordBox = ((System.Windows.Controls.PasswordBox)(target));
            return;
            case 5:
            this.showPassCheckBox = ((System.Windows.Controls.CheckBox)(target));
            
            #line 41 "..\..\..\..\Windows\Authentication\NewUser.xaml"
            this.showPassCheckBox.Checked += new System.Windows.RoutedEventHandler(this.checkBox_Checked);
            
            #line default
            #line hidden
            
            #line 41 "..\..\..\..\Windows\Authentication\NewUser.xaml"
            this.showPassCheckBox.Unchecked += new System.Windows.RoutedEventHandler(this.checkBox_Checked);
            
            #line default
            #line hidden
            return;
            case 6:
            this.registerButton = ((System.Windows.Controls.Button)(target));
            
            #line 44 "..\..\..\..\Windows\Authentication\NewUser.xaml"
            this.registerButton.Click += new System.Windows.RoutedEventHandler(this.registerButton_Click);
            
            #line default
            #line hidden
            return;
            }
            this._contentLoaded = true;
        }
    }
}
