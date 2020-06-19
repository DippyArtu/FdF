---


---

<p><img src="https://github.com/DippyArtu/FdF/blob/master/pics/fdf.png" alt="fdf"></p>
<h1 id="fdf">FdF</h1>
<p>This program uses Bresenham line drawing algorithm to create a graphical 3D representation of a landscape of a map, given as an argument.</p>
<p><strong>MacOS support only</strong></p>
<h2 id="the-map">The map</h2>
<ul>
<li>
<p>The map is a file, ending by <code>.fdf</code></p>
</li>
<li>
<p>The map can contain numbers only</p>
</li>
<li>
<p>The row corresponds to the <strong>x</strong> coordinate of a point</p>
</li>
<li>
<p>The column corresponds to the <strong>y</strong> coordinate of a point</p>
</li>
<li>
<p>The value corresponds to the <strong>z</strong> coordinate of a point</p>
</li>
<li>
<p>Each value has to be separated by a single space</p>
</li>
<li>
<p>There should not be extra characters at the end of the line</p>
</li>
<li>
<p>The map has to be a rectangle</p>
</li>
</ul>
<h3 id="an-example-of-a-valid-map">An example of a valid map:</h3>
<pre><code> 0 0 0 0 0 0
 0 0 1 1 0 0
 0 0 1 1 0 0
 0 0 0 0 0 0
</code></pre>
<h3 id="peaks">Peaks</h3>
<p>If the map consists of only two different <strong>z</strong> coordinates (i.e. 0 and 10), the wireframe will be coloured in pink for flat areas and light-green for the peak values.</p>
<p><img src="https://github.com/DippyArtu/FdF/blob/master/pics/untitled.png" alt="flats"></p>
<p>On the other hand, if there are multiple point of a varied hights, the program will build a smooth gradient between the lowest and the highest value.</p>
<p><img src="https://github.com/DippyArtu/FdF/blob/master/pics/untitled-2.png" alt="gradient"></p>
<h3 id="capabilities">Capabilities</h3>
<p>The program supports rotations of the figure in 3D, movement of the figure on screen, zoom in and out of the figure as well as increasing or decreasing the value of <strong>z</strong>.</p>
<h2 id="usage">Usage</h2>
<p>Compile the program with</p>
<pre><code>make
</code></pre>
<p>Run the program with</p>
<pre><code>./fdf *map_file_name*
</code></pre>

