using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using GMap.NET;
using GMap.NET.WindowsForms;
using GMap.NET.WindowsForms.Markers;
using GMap.NET.MapProviders;
using System.IO.Ports;


namespace GCS_MH001
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void gMapControl1_Load(object sender, EventArgs e)
        {
            // Load Google Map
            gmap.DragButton = MouseButtons.Left;
            gmap.MapProvider = GMap.NET.MapProviders.GoogleMapProvider.Instance;
            GMap.NET.GMaps.Instance.Mode = GMap.NET.AccessMode.ServerOnly;
            gmap.SetPositionByKeywords("Seoul");
            // Zoom (important sequence)
            gmap.MinZoom = 1;
            gmap.MaxZoom = 20;
            gmap.Zoom = 11;


        }

        private void start_btn_Click(object sender, EventArgs e)
        {
            // Set Marker
            GMap.NET.WindowsForms.GMapOverlay markers = new GMap.NET.WindowsForms.GMapOverlay("markers");
            GMap.NET.WindowsForms.GMapMarker marker =
                new GMap.NET.WindowsForms.Markers.GMarkerGoogle(
                    new GMap.NET.PointLatLng(37.541699, 127.078805), // Loacation of Marker
                    GMap.NET.WindowsForms.Markers.GMarkerGoogleType.red);
            markers.Markers.Add(marker);
            gmap.Overlays.Add(markers);
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {

        }

        private void eject_btn_Click(object sender, EventArgs e)
        {
            // Set Ejection Marker
            GMap.NET.WindowsForms.GMapOverlay markers = new GMap.NET.WindowsForms.GMapOverlay("markers");
            GMap.NET.WindowsForms.GMapMarker marker =
                new GMap.NET.WindowsForms.Markers.GMarkerGoogle(
                    new GMap.NET.PointLatLng(37.540358, 127.072603), // Loacation of Marker
                    GMap.NET.WindowsForms.Markers.GMarkerGoogleType.blue);
            markers.Markers.Add(marker);
            gmap.Overlays.Add(markers);
        }

        private void Rout_btn_Click(object sender, EventArgs e)
        {
            //--------- 경로 ----------//
            // PointLatLng start = new PointLatLng(37.541699, 127.078805);  // Start Point
            // PointLatLng end = new PointLatLng(37.540358, 127.072603);    // End Point
            // MapRoute route = GMap.NET.MapProviders.GoogleMapProvider.Instance.GetRoute(
            //   start, end, false, false, 15);  // Set Route
            // GMapRoute r = new GMapRoute(route.Points, "My route");
            // GMapOverlay routesOverlay = new GMapOverlay("routes");
            // routesOverlay.Routes.Add(r);
            // gmap.Overlays.Add(routesOverlay);
            // r.Stroke.Width = 2;
            // r.Stroke.Color = Color.SeaGreen;

            //---------- 직선 거리-----------//
            GMapOverlay routes = new GMapOverlay("routes");
            List<PointLatLng> points = new List<PointLatLng>();
            points.Add(new PointLatLng(37.541699, 127.078805));
            points.Add(new PointLatLng(37.540358, 127.072603));
            GMapRoute route = new GMapRoute(points, "A walk in the park");
            route.Stroke = new Pen(Color.Red, 1);
            routes.Routes.Add(route);
            gmap.Overlays.Add(routes);
        }
    }
}
