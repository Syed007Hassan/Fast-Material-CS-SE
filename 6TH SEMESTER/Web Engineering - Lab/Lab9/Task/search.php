<?php
    
include 'config.php';

$query = isset($_GET['query']) ? $_GET['query'] : '';
$search_term = $query;
$results_per_page = 1;
$current_page = isset($_GET['page']) ? $_GET['page'] : 1;
$starting_limit = ($current_page - 1) * $results_per_page;
$stmt = $pdo->prepare("SELECT * FROM users WHERE name LIKE ? OR email LIKE ? LIMIT ?, ?");
$stmt->bindValue(1, "%$query%", PDO::PARAM_STR);
$stmt->bindValue(2, "%$query%", PDO::PARAM_STR);
$stmt->bindValue(3, $starting_limit, PDO::PARAM_INT);
$stmt->bindValue(4, $results_per_page, PDO::PARAM_INT);

$stmt->execute();
$results = $stmt->fetchAll(PDO::FETCH_ASSOC);

$stmt = $pdo->prepare("SELECT COUNT(*) as count FROM users WHERE name LIKE ? OR email LIKE ?");
$stmt->bindValue(1, "%$query%", PDO::PARAM_STR);
$stmt->bindValue(2, "%$query%", PDO::PARAM_STR);
$stmt->execute();
$total_results = $stmt->fetchColumn();

$total_pages = ceil($total_results / $results_per_page);

if ($total_results > 0): ?>
    <table>
        <thead>
            <tr>
                <th>ID</th>
                <th>Name</th>
                <th>Email</th>
            </tr>
        </thead>
        <tbody>
            <?php foreach($results as $result): ?>
                <tr>
                    <td><?php echo $result['id']; ?></td>
                    <td><?php echo $result['name']; ?></td>
                    <td><?php echo $result['email']; ?></td>
                </tr>
            <?php endforeach; ?>
        </tbody>
    </table>
    <br>
    <?php if($total_pages > 1): ?>
        <div class="pagination">
            <?php if($current_page != 1): ?>
                <a href="?search_term=<?php echo $search_term ?>&page=<?php echo $current_page - 1 ?>">Previous</a>
            <?php endif; ?>
            <?php for($i=1; $i<=$total_pages; $i++): ?>
                <?php if($i == $current_page): ?>
                    <span class="current-page"><?php echo $i ?></span>
                <?php else: ?>
                    <a href="?search_term=<?php echo $search_term ?>&page=<?php echo $i ?>"><?php echo $i ?></a>
                <?php endif; ?>
            <?php endfor; ?>
            <?php if($current_page != $total_pages): ?>
                <a href="?search_term=<?php echo $search_term ?>&page=<?php echo $current_page + 1 ?>">Next</a>
            <?php endif; ?>
        </div>
    <?php endif; ?>
<?php else: ?>
    <p>No results found</p>
<?php endif; ?>


<style>
        table {
            border-collapse: collapse;
            width: 100%;
            margin: 20px 0;
            font-size: 1em;
            font-family: sans-serif;
        }
        
        table thead {
            background-color: #f2f2f2;
        }
        
        table th,
        table td {
            padding: 12px 15px;
            text-align: left;
            border-bottom: 1px solid #ddd;
        }
        
        table th {
            font-weight: bold;
            color: #555;
        }
        
        table tbody tr:hover {
            background-color: #f5f5f5;
        }
        
        .pagination {
            display: flex;
            justify-content: center;
            align-items: center;
            margin-top: 20px;
            font-size: 1.2em;
        }
        
        .pagination a,
        .current-page {
            color: #666;
            padding: 8px 16px;
            border: 1px solid #ddd;
            text-decoration: none;
        }
        
        .pagination a:hover {
            background-color: #ddd;
        }
        
        .current-page {
            background-color: #007bff;
            color: #fff;
            border: none;
        }
        
    </style>
