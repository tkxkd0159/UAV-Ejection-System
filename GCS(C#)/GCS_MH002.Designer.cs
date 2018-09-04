namespace GCS_MH001
{
    partial class Form1
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.start_btn = new System.Windows.Forms.Button();
            this.PortBox = new System.Windows.Forms.ComboBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label4 = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.gmap = new GMap.NET.WindowsForms.GMapControl();
            this.GCSbox = new System.Windows.Forms.GroupBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.label_alt = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label_long = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label_lat = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label_time = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.stop_btn = new System.Windows.Forms.Button();
            this.eject_btn = new System.Windows.Forms.Button();
            this.Rout_btn = new System.Windows.Forms.Button();
            this.TextBox = new System.Windows.Forms.TextBox();
            this.serialport = new System.IO.Ports.SerialPort(this.components);
            this.selec_btn = new System.Windows.Forms.Button();
            this.BaudBox = new System.Windows.Forms.ComboBox();
            this.groupBox1.SuspendLayout();
            this.GCSbox.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // start_btn
            // 
            this.start_btn.Location = new System.Drawing.Point(12, 229);
            this.start_btn.Name = "start_btn";
            this.start_btn.Size = new System.Drawing.Size(166, 53);
            this.start_btn.TabIndex = 1;
            this.start_btn.Text = "START";
            this.start_btn.UseVisualStyleBackColor = true;
            this.start_btn.Click += new System.EventHandler(this.start_btn_Click);
            // 
            // PortBox
            // 
            this.PortBox.FormattingEnabled = true;
            this.PortBox.Location = new System.Drawing.Point(88, 31);
            this.PortBox.Name = "PortBox";
            this.PortBox.Size = new System.Drawing.Size(117, 32);
            this.PortBox.TabIndex = 2;
            this.PortBox.Text = "선택";
            this.PortBox.SelectedIndexChanged += new System.EventHandler(this.PortBox_SelectedIndexChanged);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.BaudBox);
            this.groupBox1.Controls.Add(this.selec_btn);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Controls.Add(this.textBox1);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.PortBox);
            this.groupBox1.Location = new System.Drawing.Point(30, 22);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(398, 182);
            this.groupBox1.TabIndex = 3;
            this.groupBox1.TabStop = false;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(21, 81);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(61, 24);
            this.label4.TabIndex = 7;
            this.label4.Text = "Baud";
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(88, 130);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(116, 35);
            this.textBox1.TabIndex = 5;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(16, 133);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(66, 24);
            this.label2.TabIndex = 4;
            this.label2.Text = "State";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(28, 34);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(54, 24);
            this.label1.TabIndex = 3;
            this.label1.Text = "Port";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // gmap
            // 
            this.gmap.Bearing = 0F;
            this.gmap.CanDragMap = true;
            this.gmap.EmptyTileColor = System.Drawing.Color.Navy;
            this.gmap.GrayScaleMode = false;
            this.gmap.HelperLineOption = GMap.NET.WindowsForms.HelperLineOptions.DontShow;
            this.gmap.LevelsKeepInMemmory = 5;
            this.gmap.Location = new System.Drawing.Point(0, 11);
            this.gmap.MarkersEnabled = true;
            this.gmap.MaxZoom = 2;
            this.gmap.MinZoom = 2;
            this.gmap.MouseWheelZoomEnabled = true;
            this.gmap.MouseWheelZoomType = GMap.NET.MouseWheelZoomType.MousePositionAndCenter;
            this.gmap.Name = "gmap";
            this.gmap.NegativeMode = false;
            this.gmap.PolygonsEnabled = true;
            this.gmap.RetryLoadTile = 0;
            this.gmap.RoutesEnabled = true;
            this.gmap.ScaleMode = GMap.NET.WindowsForms.ScaleModes.Integer;
            this.gmap.SelectedAreaFillColor = System.Drawing.Color.FromArgb(((int)(((byte)(33)))), ((int)(((byte)(65)))), ((int)(((byte)(105)))), ((int)(((byte)(225)))));
            this.gmap.ShowTileGridLines = false;
            this.gmap.Size = new System.Drawing.Size(681, 476);
            this.gmap.TabIndex = 0;
            this.gmap.Zoom = 0D;
            this.gmap.Load += new System.EventHandler(this.gMapControl1_Load);
            // 
            // GCSbox
            // 
            this.GCSbox.BackColor = System.Drawing.SystemColors.AppWorkspace;
            this.GCSbox.Controls.Add(this.gmap);
            this.GCSbox.Location = new System.Drawing.Point(30, 311);
            this.GCSbox.Name = "GCSbox";
            this.GCSbox.Size = new System.Drawing.Size(681, 505);
            this.GCSbox.TabIndex = 4;
            this.GCSbox.TabStop = false;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.label_alt);
            this.groupBox2.Controls.Add(this.label9);
            this.groupBox2.Controls.Add(this.label_long);
            this.groupBox2.Controls.Add(this.label7);
            this.groupBox2.Controls.Add(this.label_lat);
            this.groupBox2.Controls.Add(this.label5);
            this.groupBox2.Controls.Add(this.label_time);
            this.groupBox2.Controls.Add(this.label3);
            this.groupBox2.Location = new System.Drawing.Point(452, 22);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(259, 271);
            this.groupBox2.TabIndex = 5;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "GPS";
            // 
            // label_alt
            // 
            this.label_alt.AutoSize = true;
            this.label_alt.Location = new System.Drawing.Point(126, 207);
            this.label_alt.Name = "label_alt";
            this.label_alt.Size = new System.Drawing.Size(96, 24);
            this.label_alt.TabIndex = 7;
            this.label_alt.Text = "000.000";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(13, 207);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(103, 24);
            this.label9.TabIndex = 6;
            this.label9.Text = "Altitude :";
            // 
            // label_long
            // 
            this.label_long.AutoSize = true;
            this.label_long.Location = new System.Drawing.Point(154, 158);
            this.label_long.Name = "label_long";
            this.label_long.Size = new System.Drawing.Size(96, 24);
            this.label_long.TabIndex = 5;
            this.label_long.Text = "000.000";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(13, 158);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(135, 24);
            this.label7.TabIndex = 4;
            this.label7.Text = "Longtitude :";
            // 
            // label_lat
            // 
            this.label_lat.AutoSize = true;
            this.label_lat.Location = new System.Drawing.Point(126, 104);
            this.label_lat.Name = "label_lat";
            this.label_lat.Size = new System.Drawing.Size(96, 24);
            this.label_lat.TabIndex = 3;
            this.label_lat.Text = "000.000";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(13, 105);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(117, 24);
            this.label5.TabIndex = 2;
            this.label5.Text = "Latitude : ";
            this.label5.Click += new System.EventHandler(this.label5_Click);
            // 
            // label_time
            // 
            this.label_time.AutoSize = true;
            this.label_time.Location = new System.Drawing.Point(94, 45);
            this.label_time.Name = "label_time";
            this.label_time.Size = new System.Drawing.Size(143, 24);
            this.label_time.TabIndex = 1;
            this.label_time.Text = "000,000.000";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(13, 45);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(75, 24);
            this.label3.TabIndex = 0;
            this.label3.Text = "Time :";
            // 
            // stop_btn
            // 
            this.stop_btn.Location = new System.Drawing.Point(248, 240);
            this.stop_btn.Name = "stop_btn";
            this.stop_btn.Size = new System.Drawing.Size(166, 53);
            this.stop_btn.TabIndex = 6;
            this.stop_btn.Text = "STOP";
            this.stop_btn.UseVisualStyleBackColor = true;
            this.stop_btn.Click += new System.EventHandler(this.button2_Click);
            // 
            // eject_btn
            // 
            this.eject_btn.Location = new System.Drawing.Point(883, 89);
            this.eject_btn.Name = "eject_btn";
            this.eject_btn.Size = new System.Drawing.Size(166, 53);
            this.eject_btn.TabIndex = 7;
            this.eject_btn.Text = "EJECT";
            this.eject_btn.UseVisualStyleBackColor = true;
            this.eject_btn.Click += new System.EventHandler(this.eject_btn_Click);
            // 
            // Rout_btn
            // 
            this.Rout_btn.Location = new System.Drawing.Point(1093, 89);
            this.Rout_btn.Name = "Rout_btn";
            this.Rout_btn.Size = new System.Drawing.Size(166, 53);
            this.Rout_btn.TabIndex = 8;
            this.Rout_btn.Text = "ROUTE";
            this.Rout_btn.UseVisualStyleBackColor = true;
            this.Rout_btn.Click += new System.EventHandler(this.Rout_btn_Click);
            // 
            // TextBox
            // 
            this.TextBox.Location = new System.Drawing.Point(752, 279);
            this.TextBox.Multiline = true;
            this.TextBox.Name = "TextBox";
            this.TextBox.Size = new System.Drawing.Size(507, 376);
            this.TextBox.TabIndex = 9;
            // 
            // selec_btn
            // 
            this.selec_btn.Location = new System.Drawing.Point(223, 31);
            this.selec_btn.Name = "selec_btn";
            this.selec_btn.Size = new System.Drawing.Size(155, 41);
            this.selec_btn.TabIndex = 8;
            this.selec_btn.Text = "CONNECT";
            this.selec_btn.UseVisualStyleBackColor = true;
            this.selec_btn.Click += new System.EventHandler(this.selec_btn_Click);
            // 
            // BaudBox
            // 
            this.BaudBox.FormattingEnabled = true;
            this.BaudBox.Items.AddRange(new object[] {
            "1200",
            "2400",
            "4800",
            "9600",
            "19200",
            "38400",
            "57600",
            "111100",
            "115200",
            "500000",
            "625000",
            "921600",
            "1500000"});
            this.BaudBox.Location = new System.Drawing.Point(88, 80);
            this.BaudBox.Name = "BaudBox";
            this.BaudBox.Size = new System.Drawing.Size(117, 32);
            this.BaudBox.TabIndex = 9;
            this.BaudBox.Text = "선택";
            this.BaudBox.SelectedIndexChanged += new System.EventHandler(this.BaudBox_SelectedIndexChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(13F, 24F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1326, 876);
            this.Controls.Add(this.TextBox);
            this.Controls.Add(this.Rout_btn);
            this.Controls.Add(this.eject_btn);
            this.Controls.Add(this.stop_btn);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.GCSbox);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.start_btn);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.GCSbox.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Button start_btn;
        private System.Windows.Forms.ComboBox PortBox;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Label label2;
        private GMap.NET.WindowsForms.GMapControl gmap;
        private System.Windows.Forms.GroupBox GCSbox;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label_lat;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label_time;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label_alt;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label_long;
        private System.Windows.Forms.Button stop_btn;
        private System.Windows.Forms.Button eject_btn;
        private System.Windows.Forms.Button Rout_btn;
        private System.Windows.Forms.TextBox TextBox;
        private System.Windows.Forms.Label label4;
        private System.IO.Ports.SerialPort serialport;
        private System.Windows.Forms.Button selec_btn;
        private System.Windows.Forms.ComboBox BaudBox;
    }
}

